#pragma once

#include <vector>
#include <string>

#include <SDL_ttf.h>
#include <lua.hpp>

class FontLoader
{
public:
  static std::vector<TTF_Font *> fonts;
  static std::vector<SDL_Texture *> textures;

  static int loadFont(lua_State *L);
  static int loadText(lua_State *L);
  static int renderText(lua_State *L);

  void syncWithLua(lua_State *L);
};
