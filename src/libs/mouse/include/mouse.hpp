#pragma once
#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "../../../../external/include/lua/lua.hpp"

class Mouse
{
public:
    static int button;
    static int buttonMode;

    static int mouseButtonUp(lua_State *L);
    static int mouseButtonDown(lua_State *L);

    void syncWithLua(lua_State *L);
};

#endif