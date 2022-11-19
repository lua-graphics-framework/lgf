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
set(WINDOW_SRCS src/libs/window/window.cpp)

set(SRCS src/main.cpp ${FONT_SRCS} ${IMAGE_SRCS} ${KEYBOARD_SRCS} ${MOUSE_SRCS} ${RECTANGLE_SRCS} ${WINDOW_SRCS})

include_directories(external/include)
link_directories(external/lib)

add_executable(LuaGraphicsFramework ${SRCS})
target_link_libraries(LuaGraphicsFramework mingw32 SDL2main SDL2 SDL2_image SDL2_ttf lua54)
