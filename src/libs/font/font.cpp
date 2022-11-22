#include <iostream>
#include <string>
#include <vector>

#include <SDL_ttf.h>
#include <lua.hpp>

#include "../renderer/include/renderer.hpp"
#include "../image/include/image.hpp"

#include "include/font.hpp"

std::vector<TTF_Font *> fonts;
std::vector<Text> text;

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
  const char *str = lua_tostring(L, 2);

  int r = lua_tointeger(L, 3);
  int g = lua_tointeger(L, 4);
  int b = lua_tointeger(L, 5);
  
  int x = lua_tonumber(L, 6);
  int y = lua_tonumber(L, 7);

  SDL_Texture *texture = Renderer::loadText(str, r, g, b, fonts[index]);
  Text txt = { texture, { r, g, b }, str, x, y };

  text.push_back(txt);
  return 0;
}

int FontLoader::renderText(lua_State *L)
{
  int index = lua_tonumber(L, 1);
  Renderer::drawText(text[index].x, text[index].y, text[index].texture);
  return 0;
}

// Changes the text's text
int FontLoader::changeText(lua_State *L)
{
  int index = lua_tonumber(L, 1);
  const char *txt = lua_tostring(L, 2);

  // Reload the texture
  SDL_Texture *newTexture = Renderer::loadText(txt, text[index].color.r, text[index].color.g, 
    text[index].color.b, fonts[index]);
  
  text[index].texture = newTexture;
  text[index].text = txt;

  return 0;
}

// Changes the text's position
int FontLoader::changePosition(lua_State *L)
{
  int index = lua_tonumber(L, 1);
  text[index].x = lua_tonumber(L, 2);
  text[index].y = lua_tonumber(L, 3);

  return 0; 
}

void FontLoader::syncWithLua(lua_State *L)
{
  lua_register(L, "loadFont", loadFont);
  lua_register(L, "loadText", loadText);
  lua_register(L, "renderText", renderText);
  lua_register(L, "changeFontText", changeText);
  lua_register(L, "changeFontPosition", changePosition);
}