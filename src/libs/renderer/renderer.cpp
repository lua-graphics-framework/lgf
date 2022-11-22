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
void Renderer::drawImg(int x, int y, unsigned int width, unsigned int height, int srcX,
  int srcY, int srcW, int srcH, SDL_Texture *texture)
{
  SDL_Rect pos = { x, y, (int)width, (int)height };
  SDL_Rect src = { srcX, srcY, srcW, srcH };

  SDL_RenderCopy(renderer, texture, nullptr, &pos);
}

// Loads some text to the screen
SDL_Texture *Renderer::loadText(const char *text, int r, int g, int b, TTF_Font *font)
{
  SDL_Color color = { (Uint8)r, (Uint8)g, (Uint8)b };
  SDL_Surface *txt = TTF_RenderText_Blended(font, text, color);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, txt);

  SDL_FreeSurface(txt);
  return texture;
}

// Draws text to the screen
void Renderer::drawText(int x, int y, SDL_Texture *text)
{
  int w{}, h{};
  SDL_QueryTexture(text, nullptr, nullptr, &w, &h);

  SDL_Rect dst = { x, y, w, h };
  SDL_RenderCopy(renderer, text, nullptr, &dst);
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
