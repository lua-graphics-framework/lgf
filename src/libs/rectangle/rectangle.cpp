#include <iostream>
#include <string>
#include <vector>

#include "include/rectangle.hpp"
#include "../renderer/include/renderer.hpp"

#include <SDL.h>
#include <lua.hpp>

// List of rectangles
std::vector<SDL_Rect> rectangles;

// Creates a new rectangle with the position and size provided
int Rectangle::create(lua_State *L)
{
  int x = lua_tonumber(L, 1);
  int y = lua_tonumber(L, 2);
  int w = lua_tonumber(L, 3);
  int h = lua_tonumber(L, 4);

  rectangles.push_back({x, y, w, h});
  return 0;
}

// Changes the color of the rectangle
int Rectangle::changeColor(lua_State *L)
{
  int r = lua_tonumber(L, 1);
  int g = lua_tonumber(L, 2);
  int b = lua_tonumber(L, 3);

  Renderer::setDrawColor(r, g, b);
  return 0;
}

// Draws the rectangle onto the renderer
int Rectangle::draw(lua_State *L)
{
  Renderer::renderRect(rectangles[lua_tonumber(L, 1)]);
  return 0;
}

// Changes the rectangle's size
int Rectangle::changeRectangleSize(lua_State *L)
{
  int idx = lua_tonumber(L, 1);
  
  rectangles[idx].w = lua_tointeger(L, 2);
  rectangles[idx].h = lua_tonumber(L, 3);

  return 0;
}

// Changes the rectangle's position
int Rectangle::changeRectanglePos(lua_State *L)
{
  int idx = lua_tonumber(L, 1);

  rectangles[idx].x = lua_tointeger(L, 2);
  rectangles[idx].y = lua_tonumber(L, 3);

  return 0;
}

// Makes these functions callable by Lua
void Rectangle::syncWithLua(lua_State *L)
{
  lua_register(L, "createRectangle", create);
  lua_register(L, "changeRectangleColor", changeColor);
  lua_register(L, "drawRectangle", draw);
}