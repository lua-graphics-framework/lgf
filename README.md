# Lua Graphics Framework

## **About**

Lua Graphics Framework (LGF) is a cross platform library for Lua that allows you to create game engines with very little boilerplate code. It _currently_ uses SDL2 under the hood to provide a fast experience. In the future, LGF aims to have its own renderer to improve runtime speeds. Demos of what you can make with LGF are shown in the `examples/` directory.

## **Using**

To use LGF, you need to install the CLI tools, which will install LGF automatically. You can also create projects with it, build and publish your game/application, etc.

## **Building**

### **Windows**

In order to build LGF on Windows, you need Git, CMake, and a C/C++ (preferably MSVC). These build instructions are for MSVC, but you can build with MinGW with some modifications.

Run these _powershell_ commands to get the LGF source code (along with its dependencies):

- `git clone --recurse-submodules -j8 https://github.com/lua-graphics-framework/lgf`
- `cd lgf`
- `mkdir build`
- `cd build`
- `cmake ..`
- `cmake --build . --config Release`

In order to run LGF on Windows, it must be included with its DLLs. Run these commands:

- `mv external\lua-5.4.4\Release\*.dll Release`
- `mv external\SDL\Release\*.dll Release`
- `mv external\SDL_image\Release\*.dll Release`
- `mv external\SDL_ttf\Release\*.dll Release`

LGF can now be found in the `release` folder!

### **Linux**

On Linux, building LGF is a lot easier. Enter the following commands:

- `sudo apt install cmake make gcc g++ -y` - These are Debian/Ubuntu instructions; translate to your Linux distro
- `git clone https://github.com/lua-graphics-framework/lgf`
- `cd lgf`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

### **macOS**

On macOS, building LGF is also easy. But, you will need Homebrew installed before proceeding. Enter the following commands:

- `brew install cmake`
- `git clone https://github.com/lua-graphics-framework/lgf`
- `cd lgf`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

Now you can use LGF.

## **Changelog**

- v0.1.2

  - Fixed/rewrote the CLI
  - Fixed mouse events
  - Fixed segfault when drawing unloaded text
  - Fixed segfault when using an unloaded font
  - Fixed updateSize() and updatePosition()
  - Added macOS support
  - Added Linux support

- v0.1.1

  - Fixed crashing when you change the position of a rectangle
  - Fixed crashing when you change the size of a rectangle
  - Removed unnecessary window.new() and rectangle.new() methods
  - Removed unnecessary mouse event variables
  - Renamed renderer.new() to renderer.create()
  - Added the ability to change the text of a font
  - Added the ability to change the position of a font
  - Added the ability to "crop" images using src rectangles
  - Added more keycodes

- v0.1.0
  - The very first release of LGF!

## **Roadmap & Status**

I currently do not recommend using LGF for commercial projects quite yet. It is a very new library with very little features. Here is a roadmap listed below:

- [x] Core modules (window, rectangle, mouse, image, etc.)
- [x] CLI tools
- [x] Linux support
- [x] OSX support
- [ ] Multiple Lua scripts support
- [ ] Packaging system
- [ ] VSCode extension
- [ ] Actual documentation
- [ ] LuaJIT
- [ ] Sound module
- [ ] Custom LGF renderer
- [ ] Custom underlying windowing system
- [ ] Android & iOS support
- [ ] Web support through WebAssembly
