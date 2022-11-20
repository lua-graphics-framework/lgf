#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <lua.hpp>

#include "include/renderer.hpp"
#include "../window/include/window.hpp"

SDL_Renderer *renderer;
bool vsync = false;

// Renderer colors
int r{}, g{}, b{};

// Creates a new renderer (call this after creating a window)
int Renderer::create(lua_State *L)
{  
  // Creating the renderer
  renderer = SDL_CreateRenderer(Window::win(), -1, SDL_RENDERER_ACCELERATED);

  if (!renderer)
  {
    std::cout << "Fatal Error: Failed trying to create a renderer. Do you have the right window parameters?\n";
    exit(1);
  }

  // Set to default background color
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  return 0;
}

// Toggles VSync
int Renderer::toggleVSync(lua_State *L)
{
  vsync = !vsync;
  SDL_RenderSetVSync(renderer, vsync);
  return 0;
}

// Clears the renderer's display
int Renderer::clearScreen(lua_State *L)
{
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderClear(renderer);
  return 0;
}

// Renders everything to the screen
int Renderer::render(lua_State *L)
{
  SDL_RenderPresent(renderer);
  return 0;
}

// Changes the renderer's background color to the color provided
int Renderer::changeColorRGB(lua_State *L)
{
  r = lua_tonumber(L, 1);
  g = lua_tonumber(L, 2);
  b = lua_tonumber(L, 3);

  return 0;
}

// Sets the renderer's draw color
void Renderer::setDrawColor(int r, int g, int b)
{
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

// Renders a rectangle
void Renderer::renderRect(SDL_Rect rect)
{
  SDL_RenderFillRect(renderer, &rect);
}

// Loads an image for rendering
SDL_Texture *Renderer::loadImg(const char *filepath)
{
  SDL_Surface *img = IMG_Load(filepath);

  if (!img)
  {
    std::cout << "Error: Image filepath \"" << filepath << "\" is invalid.\n";
    exit(1);
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, img);
  SDL_FreeSurface(img);

  return texture;
}

// Draws the loaded image
void Renderer::drawImg(int x, int y, unsigned int width, unsigned int height, SDL_Texture *texture)
{
  SDL_Rect pos = {x, y, (int)width, (int)height};
  SDL_RenderCopy(renderer, texture, nullptr, &pos);
}

// Pushes all of these functions to the Lua stack to be callable by Lua
void Renderer::syncWithLua(lua_State *L)
{
  lua_register(L, "create", create);
  lua_register(L, "toggleVSync", toggleVSync);
  lua_register(L, "clearScreen", clearScreen);
  lua_register(L, "render", render);
  lua_register(L, "changeColorRGB", changeColorRGB);
}
