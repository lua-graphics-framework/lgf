#include <iostream>
#include <string>

#include "../../../external/include/lua/lua.hpp"
#include "../../../external/include/sdl2/SDL.h"

#include "include/mouse.hpp"
#include "../window/include/window.hpp"

bool buttonDown = false;

int Mouse::button = 0;
int Mouse::buttonMode = 0;

int Mouse::mouseButtonDown(lua_State *L)
{
    int luaButton = lua_tonumber(L, 1);

    if (button == luaButton && buttonMode == 2)
    {
        buttonDown = true;
        lua_pushboolean(L, 1);
    }
    else
    {
        lua_pushboolean(L, 0);
    }

    return 1;
}

int Mouse::mouseButtonUp(lua_State *L)
{
    int luaButton = lua_tonumber(L, 1);

    if (button == luaButton && buttonMode == 1)
    {
        lua_pushboolean(L, true);
        buttonMode = 0;
    }
    else if (button == luaButton && buttonMode == 0)
    {
        lua_pushboolean(L, false);
    }

    return 1;
}

void Mouse::syncWithLua(lua_State *L)
{
    lua_register(L, "mouseButtonDown", mouseButtonDown);
    lua_register(L, "mouseButtonUp", mouseButtonUp);
}