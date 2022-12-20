module lgf
import sdl

const frame_delay = 1000 / 60

// A struct representing an LGF window
pub struct Window {
mut:
	window &sdl.Window
	renderer &sdl.Renderer
	active bool
	fps_limit int
	frame_start f64
	frame_time f64
	event sdl.Event
}

// Creates a new window
pub fn window_create(width u32, height u32, title &char) Window {
	sdl.init(sdl.init_video)

	window := sdl.create_window(title, sdl.windowpos_centered, 
		sdl.windowpos_centered, int(width), int(height), u32(sdl.WindowFlags.shown))
	
	renderer := sdl.create_renderer(window, -1, u32(sdl.RendererFlags.accelerated))

	return Window {
		window,
		renderer,
		true,
		-1,
		0,
		0,
		sdl.Event {}
	}
}

// Clears the window's renderer
pub fn (mut w Window) clear() {
	sdl.set_render_draw_color(w.renderer, 0, 0, 0, 255)
	sdl.render_clear(w.renderer)
}

// Renders everything to the screen
pub fn (mut w Window) display() {
	sdl.render_present(w.renderer)
}

// Changes the renderer's background color
pub fn (mut w Window) change_color(r int, g int, b int) {
	// TODO:
}

// Returns a boolean determining if the window created should be open
pub fn (mut w Window) active() bool {
	if w.fps_limit > 0 {
		w.frame_start = sdl.get_ticks()
	}

	return w.active
}

// Sets the window's FPS limit
pub fn (mut w Window) sync(fps int) {
	w.fps_limit = fps
}

// Polls for window events
pub fn (mut w Window) poll() {
	for sdl.poll_event(&w.event) > 0 {
		match w.event.@type {
			.quit { w.active = false }
			else {}
		}
	}
}

// TODO: icon setting, wait events

// Closes the window
pub fn (mut w Window) close() {
	sdl.destroy_renderer(w.renderer)
	sdl.destroy_window(w.window)
	sdl.quit()
}
