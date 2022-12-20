module main

import lgf
import lua
import sdl

fn main() {
	state := C.luaL_newstate()
	C.luaL_openlibs(state)

	mut window := lgf.Window { C.NULL, C.NULL, false, 0, 0, 0, sdl.Event {}, 0, 0, 0 }
	mut ref := &window

	// Window module wrapper
	window_create := fn [mut ref] (state &C.lua_State) int {
		width := C.lua_tointeger(state, 1)
		height := C.lua_tointeger(state, 2)
		title := C.lua_tostring(state, 3)

		unsafe { *ref = lgf.window_create(u32(width), u32(height), title) }
		return 0
	}

	window_clear := fn [mut ref] (state &C.lua_State) int {
		ref.clear()
		return 0
	}

	window_active := fn [mut ref] (state &C.lua_State) int {
		C.lua_pushboolean(state, int(ref.active()))
		return 1
	}

	window_display := fn [mut ref] (state &C.lua_State) int {
		ref.display()
		return 0	
	}

	window_update := fn [mut ref] (state &C.lua_State) int {
		ref.poll()
		return 0
	}

	window_sync := fn [mut ref] (state &C.lua_State) int {
		ref.sync(C.lua_tointeger(state, 1))
		return 0
	}

	window_close := fn [mut ref] (state &C.lua_State) int {
		ref.close()
		return 0
	}

	window_change_color := fn [mut ref] (state &C.lua_State) int {		
		ref.change_color(C.lua_tointeger(state, 1), C.lua_tointeger(state, 2), C.lua_tointeger(state, 3))
		return 0
	}

	C.lua_register(state, "lgf_window_create".str, &int(window_create))
	C.lua_register(state, "lgf_window_clear".str, &int(window_clear))
	C.lua_register(state, "lgf_window_active".str, &int(window_active))
	C.lua_register(state, "lgf_window_display".str, &int(window_display))
	C.lua_register(state, "lgf_window_update".str, &int(window_update))
	C.lua_register(state, "lgf_window_sync".str, &int(window_sync))
	C.lua_register(state, "lgf_window_close".str, &int(window_close))
	C.lua_register(state, "lgf_window_change_color".str, &int(window_change_color))

	C.luaL_dofile(state, "./src/lua/main.lua".str)
	C.lua_close(state)
}
