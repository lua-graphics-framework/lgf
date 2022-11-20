#include <iostream>
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <lua.hpp>

#include "include/image.hpp"
#include "../renderer/include/renderer.hpp"

std::vector<SDL_Texture *> textures;

int ImageLoader::loadImage(lua_State *L)
{
  const char *path = lua_tostring(L, 1);

  SDL_Texture *tex = Renderer::loadImg(path);
  textures.push_back(tex);

  return 0;
}

int ImageLoader::drawImage(lua_State *L)
{
  int x = lua_tonumber(L, 1);
  int y = lua_tonumber(L, 2);
  int w = lua_tonumber(L, 3);
  int h = lua_tonumber(L, 4);

  int textureIndex = lua_tonumber(L, 5);
  Renderer::drawImg(x, y, w, h, textures[textureIndex]);

  return 0;
}

void ImageLoader::syncWithLua(lua_State *L)
{
  lua_register(L, "loadImage", loadImage);
  lua_register(L, "drawImage", drawImage);
}