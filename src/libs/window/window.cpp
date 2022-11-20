#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "include/window.hpp"

// Window creation globals
bool windowCreated = false;
SDL_Window *window;
SDL_Renderer *renderer;

// Regular globals
bool windowActive = true;
bool vsync = false;

SDL_Event event;
int limit{}; // fps limit

// FPS limiting
const double frameDelay = 1000 / 60;
double frameTime;
Uint32 frameStart;

// Window color
int r{}, g{}, b{};

// Sets the SDL2 window and renderer to the local window module one
void Window::config(SDL_Window *win, SDL_Renderer *ren)
{
  if (!windowCreated && win != nullptr && ren != nullptr)
  {
    window = win;
    renderer = ren;
  }
}

// Actually creates the main SDL2 window
int Window::create(lua_State *L)
{
  if (!windowCreated)
  {
    windowCreated = true;

    // Get Lua parameters
    unsigned int width = lua_tointeger(L, 1);
    unsigned int height = lua_tointeger(L, 2);
    const char *title = lua_tostring(L, 3);

    SDL_Init(SDL_INIT_VIDEO);

    // Creating the window
    window = SDL_CreateWindow(
      title,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      width,
      height,
      SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!window)
    {
      std::cout << "Fatal Error: Failed trying to create a window. Do you have the right parameters?\n";
      exit(1);
    }

    // Creating the renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
      std::cout << "Fatal Error: Failed trying to create a renderer. Do you have the right window parameters?\n";
      exit(1);
    }

    // Set to default background color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  return 0;
}

// Returns a boolean value determining if the window should stay open
int Window::active(lua_State *L)
{
  lua_pushboolean(L, windowActive);
  return 1;
}

// Switches the FPS limit to the one provided
int Window::sync(lua_State *L)
{
  limit = lua_tonumber(L, 1);
  return 0;
}

// Updates the window
int Window::update(lua_State *L)
{
  if (limit > 0)
  {
    frameStart = SDL_GetTicks();
  }

  // Event handling
  if (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      windowActive = false;
    }
  }

  // FPS limiting
  if (limit > 0)
  {
    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  return 0;
}

// Enables VSync
int Window::setVSync(lua_State *L)
{
  SDL_RenderSetVSync(renderer, lua_toboolean(L, 1));
  return 0;
}

// Sets the window's custom icon
int Window::setIcon(lua_State *L)
{
  // TODO:
  return 0;
}

// Clears the renderer's display
int Window::clearScreen(lua_State *L)
{
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderClear(renderer);
  return 0;
}

// Renders everything to the screen
int Window::render(lua_State *L)
{
  SDL_RenderPresent(renderer);
  return 0;
}

// Changes the window's background color to the color provided
int Window::changeColorRGB(lua_State *L)
{
  r = lua_tonumber(L, 1);
  g = lua_tonumber(L, 2);
  b = lua_tonumber(L, 3);

  return 0;
}

// Closes the window
int Window::close(lua_State *L)
{
  if (window && renderer)
  {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  return 0;
}

// Pushed all of these functions to the Lua stack to be callable by Lua
void Window::syncWithLua(lua_State *L)
{
  lua_register(L, "create", create);
  lua_register(L, "active", active);
  lua_register(L, "sync", sync);
  lua_register(L, "update", update);
  lua_register(L, "setVSync", setVSync);
  lua_register(L, "setIcon", setIcon);
  lua_register(L, "clear", clearScreen);
  lua_register(L, "render", render);
  lua_register(L, "changeColorRGB", changeColorRGB);
  lua_register(L, "close", close);
}
