#include <iostream>
#include <string>

#include <lua.hpp>
#include <SDL2/SDL.h>

#include "include/mouse.hpp"
#include "../window/include/window.hpp"

bool buttonDown = false;
SDL_Event ev;

int button = 0;
int buttonMode = 0;

// Mouse position
int x;
int y;

// Returns a boolean value determining if the mouse button provided is being held down
int Mouse::mouseButtonDown(lua_State *L) {
  int luaButton = lua_tonumber(L, 1);

  // If the buttons (left, right, middle) match and the mouse button is being held down
  if (button == luaButton && buttonMode == 2) {
    buttonDown = true;
    lua_pushboolean(L, true);
    return 1;
  }

  lua_pushboolean(L, false);
  return 1;
}

// Returns a boolean value determining if the mouse button provided has been released
int Mouse::mouseButtonUp(lua_State *L) {
  int luaButton = lua_tonumber(L, 1);

  if (button == luaButton && buttonMode == 1) {
    lua_pushboolean(L, true);
    buttonMode = 0;
    return 1;
  }

  if (button == luaButton && buttonMode == 0) {
    lua_pushboolean(L, false);
  }

  return 1;
}

// Looks for mouse window events
int Mouse::pollEvents(lua_State *L) {
  buttonMode = 0;
  ev = Window::getEv();

  // Set mouse position
  SDL_GetMouseState(&x, &y);

  if (ev.type == SDL_MOUSEBUTTONDOWN) {
    buttonMode = 2;
  }

  if (ev.type == SDL_MOUSEBUTTONUP && buttonMode != 1) {
    buttonMode = 1;
  }

  button = ev.button.button;
  return 0;
}

// Returns the X position of the mouse cursor
int Mouse::getMousePosX(lua_State *L) {
  lua_pushinteger(L, x);
  return 1;
}

// Returns the Y position of the mouse cursor
int Mouse::getMousePosY(lua_State *L) {
  lua_pushinteger(L, y);
  return 1;
}

void Mouse::registerLuaFunctions(lua_State *L) {
  lua_register(L, "mouseButtonDown", mouseButtonDown);
  lua_register(L, "mouseButtonUp", mouseButtonUp);
  lua_register(L, "mousePollEvents", pollEvents);
  lua_register(L, "getMousePosX", getMousePosX);
  lua_register(L, "getMousePosY", getMousePosY);
}
