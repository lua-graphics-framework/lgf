#include <iostream>
#include <string>
#include <vector>

#include "include/rectangle.hpp"
#include "../window/include/window.hpp"

#include "../../../vendor/include/sdl2/SDL.h"
#include "../../../vendor/include/lua/lua.hpp"

int initialR, initialG, initialB;
SDL_Rect currentRect;

int rectangle::create(lua_State *L) {
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int w = lua_tonumber(L, 3);
    int h = lua_tonumber(L, 4);

    currentRect = {x, y, w, h};
    return 0;
}

int rectangle::changeColor(lua_State *L) {
    int r = lua_tonumber(L, 1);
    int g = lua_tonumber(L, 2);
    int b = lua_tonumber(L, 3);
    
    window::setDrawColor(r, g, b);
    return 0;
}

int rectangle::draw(lua_State *L) {
    window::renderRect(currentRect);
    return 0;
}

void rectangle::bindWithLua(lua_State *L) {
    lua_register(L, "createRectangle", create);
    lua_register(L, "changeRectangleColor", changeColor);
    lua_register(L, "drawRectangle", draw);
}