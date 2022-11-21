# Lua Graphics Framework

## **About**

Lua Graphics Framework (LGF) is a cross platform library for Lua that allows you to create game engines with very little boilerplate code. It *currently* uses SDL2 under the hood to provide a fast experience. In the future, LGF aims to have its own renderer to improve runtime speeds. Demos of what you can make with LGF are shown in the `examples/` directory.

## **Using**
To use LGF, you need to install the CLI tools, which will install LGF automatically. You can also create projects with it, build and publish your game/application, etc.

## **Building**
Currently, only building on Windows has been tested. Although, it is very possible for it to work on Linux/UNIX because it uses CMake as its build system.

## **Roadmap & Status**
I currently do not recommend using LGF for commercial projects quite yet. It is a very new library with very little features. Here is a roadmap listed below:

- [x] Core modules (window, rectangle, mouse, image, etc.)
- [x] CLI tools
- [ ] Packaging system
- [ ] Sound module
- [ ] Custom LGF renderer
- [ ] LuaJIT
- [ ] Custom underlying windowing system
