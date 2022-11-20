#pragma once
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include <SDL.h>
#include <lua.hpp>

namespace ImageLoader
{
  int loadImage(lua_State *L);
  int drawImage(lua_State *L);

  void syncWithLua(lua_State *L);
};

#endif