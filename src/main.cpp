#include <iostream>
#include <string>
#include <vector>

#include <lua.hpp>
#include <SDL.h>

#include "libs/window/include/window.hpp"
#include "libs/rectangle/include/rectangle.hpp"
#include "libs/mouse/include/mouse.hpp"
#include "libs/keyboard/include/keyboard.hpp"
#include "libs/image/include/image.hpp"
#include "libs/font/include/font.hpp"

lua_State *L;

SDL_Window *win;
SDL_Renderer *ren;

rectangle rect;
Mouse mouse;
Keyboard keyboard;
ImageLoader loader;
FontLoader fontLoader;

int main(int argc, char *argv[])
{
  L = luaL_newstate();
  luaL_openlibs(L);

  Window::config(win, ren);
  Window::syncWithLua(L);

  rect.bindWithLua(L);
  mouse.syncWithLua(L);
  keyboard.syncWithLua(L);
  loader.syncWithLua(L);
  fontLoader.syncWithLua(L);

  luaL_dofile(L, "./src/scripts/main.lua");
  lua_close(L);

  return 0;
}