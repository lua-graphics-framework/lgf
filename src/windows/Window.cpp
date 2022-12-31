#include <iostream>
#include <string>

#include <Windows.h>
#include "include/Windows.hpp"

HWND hwnd;

// Win32 window procedure
LRESULT CALLBACK wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
  switch (msg)
  {
  case WM_CLOSE:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProcW(hwnd, msg, wparam, lparam);
  }

  return 0;
}

// Creates a new Win32 window
void Windows::Window::create(unsigned int width, unsigned int height, const char *title)
{
  // Window class
  WNDCLASSW wc;
  wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wc.hInstance = GetModuleHandleW(NULL);
  wc.lpfnWndProc = wndproc;
  wc.lpszClassName = L"window"; // TOOD: salt this
  wc.lpszMenuName = nullptr;

  if (!RegisterClassW(&wc))
  {
    std::cout << "Error: Failed to register a Win32 window class.\n"
    "This is an internal error and must be reported to LGF's GitHub repo." << std::endl;
    exit(1);
  }

  LPWSTR newtitle = (LPWSTR)malloc(100 * sizeof(LPCWSTR));
  MultiByteToWideChar(CP_UTF8, 0, title, -1, newtitle, 100);

  // Create a window
  hwnd = CreateWindowExW(
    WS_EX_CLIENTEDGE,
    wc.lpszClassName,
    newtitle,
    WS_VISIBLE | WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    width,
    height,
    nullptr,
    nullptr,
    wc.hInstance,
    nullptr
  );

  if (!hwnd)
  {
    std::cout << "Error: Failed to create a Win32 window.\n"
    "Make sure that the width, height, and title are all correct and are not too big.\n"
    "Otherwise, this is an internal error and must be reported to LGF's GitHub repo." << std::endl;
    exit(1);
  }

  // Show the window
  ShowWindow(hwnd, SW_SHOW);
  UpdateWindow(hwnd);
}

// Closes the window
void Windows::Window::destroy()
{
  if (hwnd != nullptr)
  {
    DestroyWindow(hwnd);
  }
  else
  {
    std::cout << "Warning: Attempted to double-destroy a window." << std::endl;
  }
}

HWND Windows::Window::getWindowHandle()
{
  return hwnd;
}
