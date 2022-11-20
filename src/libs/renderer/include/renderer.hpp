#pragma once

#include <lua.hpp>
#include <SDL.h>

namespace Renderer
{
  int create(lua_State *L);
  int toggleVSync(lua_State *L);
  int clearScreen(lua_State *L);
  int render(lua_State *L);
  int changeColorRGB(lua_State *L);

  void setDrawColor(int r, int g, int b);
  void renderRect(SDL_Rect rect);

  SDL_Texture *loadImg(const char *filepath);
  void drawImg(int x, int y, unsigned int width, unsigned int height, SDL_Texture *texture);

  void syncWithLua(lua_State *L);
}
