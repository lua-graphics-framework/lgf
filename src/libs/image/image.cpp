#include <iostream>
#include <string>
#include <vector>

#include "../../../external/include/sdl2/SDL.h"
#include "../../../external/include/sdl2/SDL_image.h"
#include "../../../external/include/lua/lua.hpp"

#include "include/image.hpp"
#include "../window/include/window.hpp"

std::vector<SDL_Texture *> ImageLoader::textures;

int ImageLoader::loadImage(lua_State *L)
{
    const char *path = lua_tostring(L, 1);

    SDL_Texture *tex = window::loadImage(path);
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
    window::drawImage(x, y, w, h, textures[textureIndex]);

    return 0;
}

void ImageLoader::syncWithLua(lua_State *L)
{
    lua_register(L, "loadImage", loadImage);
    lua_register(L, "drawImage", drawImage);
}