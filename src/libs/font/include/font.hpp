#pragma once
#ifndef FONT_HPP
#define FONT_HPP

#include <vector>
#include <string>

#include "../../../../vendor/include/sdl2/SDL_ttf.h"
#include "../../../../vendor/include/lua/lua.hpp"

class FontLoader {
    public:
        static std::vector<TTF_Font *> fonts;
        static std::vector<SDL_Texture *> textures;

        static int loadFont(lua_State *L);
        static int loadText(lua_State *L);
        static int renderText(lua_State *L);

        void syncWithLua(lua_State *L);
};

#endif