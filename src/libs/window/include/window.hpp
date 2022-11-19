#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include "../../../../vendor/include/sdl2/SDL.h"
#include "../../../../vendor/include/sdl2/SDL_ttf.h"
#include "../../../../vendor/include/lua/lua.hpp"

class window {
    public:
        window(SDL_Window *window, SDL_Renderer *renderer);

        static int create(lua_State *L);
        static int isCloseRequested(lua_State *L);

        static int sync(lua_State *L);
        static int update(lua_State *L);

        static int setVSync(lua_State *L);
        static int setIcon(lua_State *L);
        
        static int clearScreen(lua_State *L);
        static int render(lua_State *L);

        static void setDrawColor(int r, int g, int b);
        static void renderRect(SDL_Rect rect);
        
        static int changeColorRGB(lua_State *L);
        static int close(lua_State *L);

        static SDL_Texture *loadImage(const char *path);
        static void drawImage(int x, int y, int w, int h, SDL_Texture *texture);

        static TTF_Font *loadFont(const char *path, int size);
        static SDL_Texture *drawText(const char *text, TTF_Font *font);
        static void renderText(int x, int y, SDL_Texture *texture);

        void syncWithLua(lua_State *L);
};

#endif