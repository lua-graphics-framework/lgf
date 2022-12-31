cmake_minimum_required(VERSION 3.0)
project(LuaGraphicsFramework VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(MSVC OR MINGW OR CYGWIN OR MSYS)
  set(PLATFORM_SRCS src/windows/Window.cpp src/windows/Event.cpp)
endif(MSVC OR MINGW OR CYGWIN OR MSYS)

set(SRCS ${PLATFORM_SRCS} src/Main.cpp)

add_executable(LuaGraphicsFramework ${SRCS})

if(MSVC OR MINGW OR CYGWIN OR MSYS)
  target_link_libraries(LuaGraphicsFramework user32 kernel32 gdi32 opengl32)
endif(MSVC OR MINGW OR CYGWIN OR MSYS)
