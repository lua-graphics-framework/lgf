#pragma once
#include <lua.hpp>

namespace Renderer
{
  int create(lua_State *L);
  int toggleVSync(lua_State *L);
  int clearScreen(lua_State *L);
  int render(lua_State *L);
  int changeColorRGB(lua_State *L);

  void syncWithLua(lua_State *L);
}
