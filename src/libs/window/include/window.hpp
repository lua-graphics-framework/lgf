#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include <SDL.h>
#include <SDL_ttf.h>
#include <lua.hpp>

namespace Window
{
  void config(SDL_Window *window);
  void beforeClear();

  int create(lua_State *L);
  int active(lua_State *L);

  int sync(lua_State *L);
  int update(lua_State *L);

  int setIcon(lua_State *L);
  void renderRect(SDL_Rect rect);
  int close(lua_State *L);

  SDL_Texture *loadImage(const char *path);
  void drawImage(int x, int y, int w, int h, SDL_Texture *texture);

  TTF_Font *loadFont(const char *path, int size);
  SDL_Texture *drawText(const char *text, TTF_Font *font);
  void renderText(int x, int y, SDL_Texture *texture);

  void syncWithLua(lua_State *L);
  SDL_Window *win();
};

#endif