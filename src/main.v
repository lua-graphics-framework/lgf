module main

import lgf
import lua
import sdl

fn main() {
	state := C.luaL_newstate()
	C.luaL_openlibs(state)

	mut window := lgf.Window { C.NULL, C.NULL, false, 0, 0, 0, sdl.Event {} }

	// Window module wrapper
	window_create := fn [mut window] (state &C.lua_State, width int, height int, title &char) int {
		window = lgf.window_create(u32(width), u32(height), title)
		return 0
	}

	window_clear := fn [mut window] (state &C.lua_State) int {
		window.clear()
		return 0
	}

	window_display := fn [mut window] (state &C.lua_State) int {
		window.display()
		return 0	
	}

	window_update := fn [mut window] (state &C.lua_State) int {
		window.poll()
		return 0	
	}

	window_sync := fn [mut window] (state &C.lua_State, fps_limit int) int {
		window.sync(fps_limit)
		return 0
	}

	window_close := fn [mut window] (state &C.lua_State) int {
		window.close()
		return 0
	}

	C.lua_register(state, "lgf_window_create".str, &int(window_create))
	C.lua_register(state, "lgf_window_display".str, &int(window_create))
	C.lua_register(state, "lgf_window_create".str, &int(window_create))
	C.lua_register(state, "lgf_window_create".str, &int(window_create))
	C.lua_register(state, "lgf_window_create".str, &int(window_create))
	C.lua_register(state, "lgf_window_create".str, &int(window_create))

	C.luaL_dofile(state, "./src/lua/main.lua".str)
	C.lua_close(state)
}
