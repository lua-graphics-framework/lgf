#pragma once
#include <lua.hpp>

namespace Keyboard
{
  int keyup(lua_State *L);
  int keydown(lua_State *L);
  int poll(lua_State *L);

  void syncWithLua(lua_State *L);
};
