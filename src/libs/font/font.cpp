#include <iostream>
#include <string>
#include <vector>

#include "../../../external/include/sdl2/SDL_ttf.h"
#include "../../../external/include/lua/lua.hpp"

#include "../window/include/window.hpp"
#include "../image/include/image.hpp"

#include "include/font.hpp"

std::vector<TTF_Font *> FontLoader::fonts;
std::vector<SDL_Texture *> FontLoader::textures;

int FontLoader::loadFont(lua_State *L)
{
    const char *path = lua_tostring(L, 1);
    int size = lua_tonumber(L, 2);

    TTF_Font *font = window::loadFont(path, size);
    fonts.push_back(font);

    return 0;
}

int FontLoader::loadText(lua_State *L)
{
    int index = lua_tonumber(L, 1);
    const char *text = lua_tostring(L, 2);

    SDL_Texture *texture = window::drawText(text, fonts[index]);
    textures.push_back(texture);

    return 0;
}

int FontLoader::renderText(lua_State *L)
{
    int index = lua_tonumber(L, 1);
    int x = lua_tonumber(L, 2);
    int y = lua_tonumber(L, 3);

    window::renderText(x, y, textures[index]);
    return 0;
}

void FontLoader::syncWithLua(lua_State *L)
{
    lua_register(L, "loadFont", loadFont);
    lua_register(L, "loadText", loadText);
    lua_register(L, "renderText", renderText);
}