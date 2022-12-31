#pragma once
#include <Windows.h>

namespace Window
{
  void create(unsigned int width, unsigned int height, const char *title);
  void destroy();
  HWND getWindowHandle();
}
