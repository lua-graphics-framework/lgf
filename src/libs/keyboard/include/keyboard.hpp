#pragma once
#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "../../../../external/include/lua/lua.hpp"

class Keyboard
{
public:
    static int key;

    static int keyup(lua_State *L);
    static int keydown(lua_State *L);

    void syncWithLua(lua_State *L);
};

#endif