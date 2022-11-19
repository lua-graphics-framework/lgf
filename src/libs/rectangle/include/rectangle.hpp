#pragma once
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../../../../vendor/include/sdl2/SDL.h"
#include "../../../../vendor/include/lua/lua.hpp"

class rectangle {
    public:
        static int create(lua_State *L);
        static int changeColor(lua_State *L);
        static int draw(lua_State *L);

        void bindWithLua(lua_State *L);
};

#endif