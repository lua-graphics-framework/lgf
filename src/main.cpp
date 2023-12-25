#include <iostream>
#include <string>
#include <vector>

#include <lua.hpp>
#include <SDL2/SDL.h>

#include "libs/window/include/window.hpp"
#include "libs/renderer/include/renderer.hpp"
#include "libs/rectangle/include/rectangle.hpp"
#include "libs/mouse/include/mouse.hpp"
#include "libs/keyboard/include/keyboard.hpp"
#include "libs/image/include/image.hpp"
#include "libs/font/include/font.hpp"

SDL_Window *win;
SDL_Renderer *ren;

int main(int argc, char *argv[]) {
  // Make sure a Lua script argument has been given
  if (argc == 1) {
    std::cout << "Give a Lua script's file location!" << std::endl;
    exit(1);
  }

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  Window::registerLuaFunctions(L);
  Renderer::registerLuaFunctions(L);
  Rectangle::registerLuaFunctions(L);
  Mouse::registerLuaFunctions(L);
  Keyboard::registerLuaFunctions(L);
  ImageLoader::registerLuaFunctions(L);
  FontLoader::registerLuaFunctions(L);

  luaL_dofile(L, argv[1]);
  std::cout << lua_tostring(L, -1) << std::endl;
  lua_close(L);

  return 0;
}
