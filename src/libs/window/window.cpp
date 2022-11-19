#include <iostream>
#include <string>

#include "include/window.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <lua.hpp>

#include "../keyboard/include/keyboard.hpp"
#include "../keyboard/include/keycode.hpp"

#include "../mouse/include/mouse.hpp"
#include "../image/include/image.hpp"

SDL_Event sdlEvent;
bool windowOpen = true;

Uint32 frameStart;
int frameTime;
int frameDelay;

bool closeRequested = false;
int fpsLimit = 0;

SDL_Window *sdlWindow;
SDL_Renderer *sdlRenderer;

window::window(SDL_Window *window, SDL_Renderer *renderer)
{
  sdlWindow = window;
  sdlRenderer = renderer;
}

int window::create(lua_State *L)
{
  const char *title = lua_tostring(L, 1);
  int width = lua_tonumber(L, 2);
  int height = lua_tonumber(L, 3);

  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();

  sdlWindow = SDL_CreateWindow(
      title,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      width,
      height,
      SDL_WINDOW_SHOWN);

  if (!sdlWindow)
  {
    std::cout << "Failed to create a window\n";
    windowOpen = false;
  }

  sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);

  if (!sdlRenderer)
  {
    std::cout << "Failed to create a renderer.\n";
    windowOpen = false;
  }

  return 0;
}

int window::isCloseRequested(lua_State *L)
{
  lua_pushboolean(L, closeRequested);
  return 1;
}

int window::setVSync(lua_State *L)
{
  int mode = lua_tonumber(L, 1);

  if (mode == 0)
  {
    SDL_RenderSetVSync(sdlRenderer, 0);
  }
  else if (mode == 1)
  {
    SDL_RenderSetVSync(sdlRenderer, 1);
  }

  return 0;
}

int window::setIcon(lua_State *L)
{
  const char *path = lua_tostring(L, 1);

  SDL_Surface *icon = IMG_Load(path);
  SDL_SetWindowIcon(sdlWindow, icon);

  SDL_FreeSurface(icon);

  return 0;
}

int window::sync(lua_State *L)
{
  int fps = lua_tonumber(L, 1);

  fpsLimit = fps;
  frameDelay = 1000 / fpsLimit;

  return 0;
}

int window::update(lua_State *L)
{
  if (fpsLimit != 0)
  {
    frameStart = SDL_GetTicks();
  }

  frameStart = SDL_GetTicks();

  SDL_PollEvent(&sdlEvent);
  if (sdlEvent.type == SDL_QUIT)
  {
    closeRequested = true;
  }
  else if (sdlEvent.type == SDL_MOUSEBUTTONUP)
  {
    if (sdlEvent.button.button == SDL_BUTTON_LEFT)
    {
      Mouse::button = 1;
      Mouse::buttonMode = 1;
    }
    else if (sdlEvent.button.button == SDL_BUTTON_MIDDLE)
    {
      Mouse::button = 2;
      Mouse::buttonMode = 1;
    }
    else if (sdlEvent.button.button == SDL_BUTTON_RIGHT)
    {
      Mouse::button = 3;
      Mouse::buttonMode = 1;
    }
  }
  else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
  {
    if (sdlEvent.button.button == SDL_BUTTON_LEFT)
    {
      Mouse::button = 1;
      Mouse::buttonMode = 2;
    }
    else if (sdlEvent.button.button == SDL_BUTTON_MIDDLE)
    {
      Mouse::button = 2;
      Mouse::buttonMode = 2;
    }
    else if (sdlEvent.button.button == SDL_BUTTON_RIGHT)
    {
      Mouse::button = 3;
      Mouse::buttonMode = 2;
    }
  }

  if (fpsLimit != 0)
  {
    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  return 0;
}

SDL_Texture *window::loadImage(const char *path)
{
  SDL_Surface *image = IMG_Load(path);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(sdlRenderer, image);

  SDL_FreeSurface(image);
  return texture;
}

void window::drawImage(int x, int y, int w, int h, SDL_Texture *texture)
{
  SDL_Rect pos = {x, y, w, h};
  SDL_RenderCopy(sdlRenderer, texture, NULL, &pos);
}

int window::clearScreen(lua_State *L)
{
  SDL_RenderClear(sdlRenderer);
  return 0;
}

int window::render(lua_State *L)
{
  SDL_RenderPresent(sdlRenderer);
  return 0;
}

int window::changeColorRGB(lua_State *L)
{
  int r = lua_tonumber(L, 1);
  int g = lua_tonumber(L, 2);
  int b = lua_tonumber(L, 3);

  SDL_SetRenderDrawColor(sdlRenderer, r, g, b, 255);
  SDL_RenderClear(sdlRenderer);
  SDL_RenderPresent(sdlRenderer);

  return 0;
}

int window::close(lua_State *L)
{
  SDL_DestroyRenderer(sdlRenderer);
  SDL_DestroyWindow(sdlWindow);

  for (unsigned int i = 0; i < ImageLoader::textures.size(); i++)
  {
    SDL_DestroyTexture(ImageLoader::textures[i]);
  }

  ImageLoader::textures.clear();

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();

  return 0;
}

TTF_Font *window::loadFont(const char *path, int size)
{
  TTF_Font *font = TTF_OpenFont(path, size);
  return font;
}

SDL_Texture *window::drawText(const char *text, TTF_Font *font)
{
  SDL_Color color = {255, 255, 255};

  SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(sdlRenderer, surface);

  SDL_FreeSurface(surface);
  return texture;
}

void window::renderText(int x, int y, SDL_Texture *texture)
{
  int texW, texH;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

  SDL_Rect pos = {x, y, texW, texH};
  SDL_RenderCopy(sdlRenderer, texture, NULL, &pos);
}

void window::setDrawColor(int r, int g, int b)
{
  SDL_SetRenderDrawColor(sdlRenderer, r, g, b, 255);
}

void window::renderRect(SDL_Rect rect)
{
  SDL_RenderFillRect(sdlRenderer, &rect);
  SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
}

void window::syncWithLua(lua_State *L)
{
  lua_register(L, "create", create);
  lua_register(L, "sync", sync);
  lua_register(L, "setVSync", setVSync);
  lua_register(L, "setIcon", setIcon);
  lua_register(L, "update", update);
  lua_register(L, "close", close);
  lua_register(L, "clearScreen", clearScreen);
  lua_register(L, "display", render);
  lua_register(L, "isCloseRequested", isCloseRequested);
  lua_register(L, "windowChangeColor", changeColorRGB);
}