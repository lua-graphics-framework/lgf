#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include <lua.hpp>

namespace ImageLoader {

int loadImage(lua_State *L);
int drawImage(lua_State *L);

void registerLuaFunctions(lua_State *L);

};
