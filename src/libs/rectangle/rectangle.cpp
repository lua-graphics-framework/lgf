#include <iostream>
#include <string>
#include <vector>

#include "include/rectangle.hpp"
#include "../window/include/window.hpp"

#include <SDL.h>
#include <lua.hpp>

int initialR, initialG, initialB;
std::vector<SDL_Rect> rectangles;

int Rectangle::create(lua_State *L)
{
  int x = lua_tonumber(L, 1);
  int y = lua_tonumber(L, 2);
  int w = lua_tonumber(L, 3);
  int h = lua_tonumber(L, 4);

  SDL_Rect rect = {x, y, w, h};
  rectangles.push_back(rect);

  return 0;
}

int Rectangle::changeColor(lua_State *L)
{
  int r = lua_tonumber(L, 1);
  int g = lua_tonumber(L, 2);
  int b = lua_tonumber(L, 3);

  // window::setDrawColor(r, g, b);
  return 0;
}

int Rectangle::draw(lua_State *L)
{
  // window::renderRect(lua_tonumber(L, 1));
  return 0;
}

void Rectangle::syncWithLua(lua_State *L)
{
  lua_register(L, "createRectangle", create);
  lua_register(L, "changeRectangleColor", changeColor);
  lua_register(L, "drawRectangle", draw);
}