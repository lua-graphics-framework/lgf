#pragma once
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include "../../../../external/include/sdl2/SDL.h"
#include "../../../../external/include/lua/lua.hpp"

class ImageLoader {
    public:
        static std::vector<SDL_Texture *> textures;

        static int loadImage(lua_State *L);
        static int drawImage(lua_State *L);

        void syncWithLua(lua_State *L);
};

#endif