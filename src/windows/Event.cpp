#include <iostream>
#include <string>

#include <Windows.h>
#include "include/Windows.hpp"

MSG msg;
bool shouldClose = false;

// Polls for window events
void Windows::Event::poll()
{
  while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE) > 0)
  {
    if (msg.message == WM_QUIT)
    {
      shouldClose = true;
    }

    TranslateMessage(&msg);
    DispatchMessageW(&msg);
  }
}

// Returns a boolean value determining if the window should close
bool Windows::Event::isCloseRequested()
{
  return shouldClose;
}
