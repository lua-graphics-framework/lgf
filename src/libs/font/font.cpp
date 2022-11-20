#include <iostream>
#include <string>
#include <vector>

#include <SDL_ttf.h>
#include <lua.hpp>

#include "../renderer/include/renderer.hpp"
#include "../image/include/image.hpp"

#include "include/font.hpp"

std::vector<TTF_Font *> fonts;
std::vector<SDL_Texture *> fontTextures;

int FontLoader::loadFont(lua_State *L)
{
  const char *path = lua_tostring(L, 1);
  int size = lua_tonumber(L, 2);

  TTF_Font *font = TTF_OpenFont(path, size);
  
  if (!font)
  {
    std::cout << "Error: Invalid font path \"" << path << "\".\n";
    exit(1);
  }

  fonts.push_back(font);
  return 0;
}

int FontLoader::loadText(lua_State *L)
{
  int index = lua_tonumber(L, 1);
  const char *text = lua_tostring(L, 2);

  int r = lua_tointeger(L, 3);
  int g = lua_tointeger(L, 4);
  int b = lua_tointeger(L, 5);

  SDL_Texture *texture = Renderer::loadText(text, r, g, b, fonts[index]);
  fontTextures.push_back(texture);

  return 0;
}

int FontLoader::renderText(lua_State *L)
{
  int index = lua_tonumber(L, 1);
  int x = lua_tonumber(L, 2);
  int y = lua_tonumber(L, 3);

  Renderer::drawText(x, y, fontTextures[index]);
  return 0;
}

void FontLoader::syncWithLua(lua_State *L)
{
  lua_register(L, "loadFont", loadFont);
  lua_register(L, "loadText", loadText);
  lua_register(L, "renderText", renderText);
}