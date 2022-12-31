#include <iostream>
#include <string>

#include "windows/include/Windows.hpp"

int main(int argc, char *argv[])
{
  Windows::Window::create(1280, 720, "LGF");

  while (!Windows::Event::isCloseRequested())
  {
    Windows::Event::poll();
  }

  Windows::Window::destroy();

  return 0;
}
