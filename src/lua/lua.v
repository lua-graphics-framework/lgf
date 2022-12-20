module lua

#include "@VROOT/external/lua-5.4.4/src/lapi.c"
#include "@VROOT/external/lua-5.4.4/src/lauxlib.c"
#include "@VROOT/external/lua-5.4.4/src/lbaselib.c"
#include "@VROOT/external/lua-5.4.4/src/lcode.c"
#include "@VROOT/external/lua-5.4.4/src/lcorolib.c"
#include "@VROOT/external/lua-5.4.4/src/lctype.c"
#include "@VROOT/external/lua-5.4.4/src/ldblib.c"
#include "@VROOT/external/lua-5.4.4/src/ldebug.c"
#include "@VROOT/external/lua-5.4.4/src/ldo.c"
#include "@VROOT/external/lua-5.4.4/src/ldump.c"
#include "@VROOT/external/lua-5.4.4/src/lfunc.c"
#include "@VROOT/external/lua-5.4.4/src/lgc.c"
#include "@VROOT/external/lua-5.4.4/src/linit.c"
#include "@VROOT/external/lua-5.4.4/src/liolib.c"
#include "@VROOT/external/lua-5.4.4/src/llex.c"
#include "@VROOT/external/lua-5.4.4/src/lmathlib.c"
#include "@VROOT/external/lua-5.4.4/src/lmem.c"
#include "@VROOT/external/lua-5.4.4/src/loadlib.c"
#include "@VROOT/external/lua-5.4.4/src/lobject.c"
#include "@VROOT/external/lua-5.4.4/src/lopcodes.c"
#include "@VROOT/external/lua-5.4.4/src/loslib.c"
#include "@VROOT/external/lua-5.4.4/src/lparser.c"
#include "@VROOT/external/lua-5.4.4/src/lstate.c"
#include "@VROOT/external/lua-5.4.4/src/lstring.c"
#include "@VROOT/external/lua-5.4.4/src/lstrlib.c"
#include "@VROOT/external/lua-5.4.4/src/ltable.c"
#include "@VROOT/external/lua-5.4.4/src/ltablib.c"
#include "@VROOT/external/lua-5.4.4/src/ltm.c"
#include "@VROOT/external/lua-5.4.4/src/lundump.c"
#include "@VROOT/external/lua-5.4.4/src/lutf8lib.c"
#include "@VROOT/external/lua-5.4.4/src/lvm.c"
#include "@VROOT/external/lua-5.4.4/src/lzio.c"
#flag -llua

pub fn C.luaL_newstate() &C.lua_State
pub fn C.luaL_openlibs(L &C.lua_State)
pub fn C.luaL_dofile(L &C.lua_State, filename &char)
pub fn C.lua_close(L &C.lua_State)
pub fn C.lua_register(L &C.lua_State, name &char, func &int)
