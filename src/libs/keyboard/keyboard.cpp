#include <iostream>
#include <string>

#include <lua.hpp>
#include <SDL.h>

#include "include/keyboard.hpp"
#include "include/keycode.hpp"
#include "../window/include/window.hpp"

bool keyDown = false;
int Keyboard::key = 0;

int Keyboard::keyup(lua_State *L)
{
  if (key != 0)
  {
    if (keyDown == true)
    {
      keyDown = false;
    }
  }

  lua_pushnumber(L, key);
  key = 0;

  return 1;
}

int Keyboard::keydown(lua_State *L)
{
  if (key != 0)
  {
    keyDown = true;
    lua_pushnumber(L, key);
  }
  else
  {
    return 0;
  }

  return 1;
}

void Keyboard::syncWithLua(lua_State *L)
{
  lua_register(L, "keyup2", keyup);
  lua_register(L, "keydown", keydown);
}