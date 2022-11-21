#pragma once
#include <lua.hpp>

namespace Rectangle
{
  int create(lua_State *L);
  int changeColor(lua_State *L);
  int draw(lua_State *L);

  int changeRectanglePos(lua_State *L);
  int changeRectangleSize(lua_State *L);

  void syncWithLua(lua_State *L);
};
