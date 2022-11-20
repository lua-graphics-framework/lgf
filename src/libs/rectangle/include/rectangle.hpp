#pragma once
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SDL.h>
#include <lua.hpp>

namespace Rectangle
{
  int create(lua_State *L);
  int changeColor(lua_State *L);
  int draw(lua_State *L);

  void syncWithLua(lua_State *L);
};

#endif