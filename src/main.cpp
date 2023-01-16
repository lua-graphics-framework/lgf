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

int main(int argc, char *argv[])
{
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  
  Window::syncWithLua(L);
  Renderer::syncWithLua(L);
  Rectangle::syncWithLua(L);
  Mouse::syncWithLua(L);
  Keyboard::syncWithLua(L);
  ImageLoader::syncWithLua(L);
  FontLoader::syncWithLua(L);
 
  luaL_dofile(L, argv[1]);
  lua_close(L);

  return 0;
}
