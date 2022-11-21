cmake_minimum_required(VERSION 3.23)

project(LuaGraphicsFramework)
set(PROJECT_VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(FONT_SRCS src/libs/font/font.cpp)
set(IMAGE_SRCS src/libs/image/image.cpp)
set(KEYBOARD_SRCS src/libs/keyboard/keyboard.cpp)
set(MOUSE_SRCS src/libs/mouse/mouse.cpp)
set(RECTANGLE_SRCS src/libs/rectangle/rectangle.cpp)
set(RENDERER_SRCS src/libs/renderer/renderer.cpp)
set(WINDOW_SRCS src/libs/window/window.cpp)

set(SRCS src/main.cpp ${FONT_SRCS} ${IMAGE_SRCS} ${KEYBOARD_SRCS} ${MOUSE_SRCS} 
  ${RECTANGLE_SRCS} ${WINDOW_SRCS} ${RENDERER_SRCS})

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_image)
add_subdirectory(external/SDL_ttf)
add_subdirectory(external/lua-5.4.4)

include_directories(external/SDL/include)
include_directories(external/SDL_image)
include_directories(external/SDL_ttf)
include_directories(external/lua-5.4.4/src)

add_library(LuaGraphicsFramework ${SRCS})
target_link_libraries(LuaGraphicsFramework mingw32 SDL2main SDL2 SDL2_image SDL2_ttf lua)
