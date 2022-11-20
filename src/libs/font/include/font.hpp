#pragma once
#include <lua.hpp>

namespace FontLoader
{
  int loadFont(lua_State *L);
  int loadText(lua_State *L);
  int renderText(lua_State *L);

  void syncWithLua(lua_State *L);
};
