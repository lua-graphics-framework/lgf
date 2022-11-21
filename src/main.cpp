#include <iostream>
#include <string>
#include <vector>

#include <lua.hpp>
#include <SDL.h>

#include "libs/window/include/window.hpp"
#include "libs/renderer/include/renderer.hpp"
#include "libs/rectangle/include/rectangle.hpp"
#include "libs/mouse/include/mouse.hpp"
#include "libs/keyboard/include/keyboard.hpp"
#include "libs/image/include/image.hpp"
#include "libs/font/include/font.hpp"

SDL_Window *win;
SDL_Renderer *ren;

luaL_Reg lgf[] =
{
  // Window
  { "windowCreate", Window::create },
  { "active", Window::active },
  { "sync", Window::sync },
  { "update", Window::update },
  { "setIcon", Window::setIcon },
  { "close", Window::close },

  // Renderer
  { "create", Renderer::create },
  { "toggleVSync", Renderer::toggleVSync },
  { "clearScreen", Renderer::clearScreen },
  { "render", Renderer::render },
  { "changeColorRGB", Renderer::changeColorRGB },

  // Rectangle
  { "createRectangle", Rectangle::create },
  { "changeRectangleColor", Rectangle::changeColor },
  { "drawRectangle", Rectangle::draw },
  { "changeRectangleSize", Rectangle::changeRectangleSize },
  { "changeRectanglePos", Rectangle::changeRectanglePos },

  // Mouse
  { "mouseButtonDown", Mouse::mouseButtonDown },
  { "mouseButtonUp", Mouse::mouseButtonUp },
  { "mousePollEvents", Mouse::pollEvents },
  { "getMousePosX", Mouse::getMousePosX },
  { "getMousePosY", Mouse::getMousePosY },

  // Keyboard
  { "keyup", Keyboard::keyup },
  { "keydown", Keyboard::keydown },
  { "pollKeyboard", Keyboard::poll },

  // Image
  { "loadImage", ImageLoader::loadImage },
  { "drawImage", ImageLoader::drawImage },

  // Font
  { "loadFont", FontLoader::loadFont },
  { "loadText", FontLoader::loadText },
  { "renderText", FontLoader::renderText },

  NULL, NULL
};

extern "C" int luaopen_libLuaGraphicsFramework(lua_State *L)
{
  Window::config(win);
  luaL_newlib(L, lgf);
  return 1;
}