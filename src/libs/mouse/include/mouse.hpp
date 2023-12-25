#pragma once
#include <lua.hpp>

namespace Mouse {

int mouseButtonUp(lua_State *L);
int mouseButtonDown(lua_State *L);
int pollEvents(lua_State *L);

int getMousePosX(lua_State *L);
int getMousePosY(lua_State *L);

void registerLuaFunctions(lua_State *L);

};
