#include <iostream>
#include <string>

#include <lua.hpp>
#include <SDL2/SDL.h>

#include "include/keyboard.hpp"
#include "include/keycode.hpp"
#include "../window/include/window.hpp"

bool keyDown = false;
int key = 0;

int Keyboard::keyup(lua_State *L) {
  if (key != 0 && keyDown) {
    keyDown = false;
  }

  lua_pushnumber(L, key);
  key = 0;

  return 1;
}

int Keyboard::keydown(lua_State *L)
{
  if (key != 0) {
    keyDown = true;
    lua_pushnumber(L, key);
    return 1;
  }

  return 0;
}

// Polls keyboard events
int Keyboard::poll(lua_State *L) {
  SDL_Event event = Window::getEv();

  if (event.type == SDL_KEYDOWN) {
    key = event.key.keysym.sym;
  }

  if (event.type == SDL_KEYUP) {
    key = 0;
  }

  return 0;
}

void Keyboard::registerLuaFunctions(lua_State *L) {
  lua_register(L, "keyup", keyup);
  lua_register(L, "keydown", keydown);
  lua_register(L, "pollKeyboard", poll);
}
