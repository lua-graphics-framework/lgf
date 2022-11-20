#pragma once

#include <lua.hpp>
#include <SDL.h>
#include <SDL_ttf.h>

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
  void drawText(int x, int y, SDL_Texture *text);

  SDL_Texture *loadText(const char *text, int r, int g, int b, TTF_Font *font);

  void syncWithLua(lua_State *L);
}
