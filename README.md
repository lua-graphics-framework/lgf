# Lua Graphics Framework

## **About**

Lua Graphics Framework (LGF) is a cross platform library for Lua that allows you to create game engines with very little boilerplate code. It *currently* uses SDL2 under the hood to provide a fast experience. In the future, LGF aims to have its own renderer to improve runtime speeds. Demos of what you can make with LGF are shown in the `examples/` directory.

## **Using**
To use LGF, you need to install the CLI tools, which will install LGF automatically. You can also create projects with it, build and publish your game/application, etc.

## **Building**
### **Windows**
Now, building LGF on Windows is a big pain currently. I would recommend just installing the CLI. But if you really want to, you need to install Git, CMake, MinGW or Visual Studio 2022, and Lua. Then, run these Powershell commands to get a copy of LGF:
- `git clone --recursive https://github.com/lua-graphics-framework/lgf` - note that this will take a while depending on your internet connection speeds
- `cd lgf`

Next, you need to build Freetype. This is needed by SDL2_ttf. To do that, enter these Powershell commands:
- `cd external/freetype`
- `mkdir build`
- `cd build`
- `cmake .. -G "MinGW Makefiles"` - use this command if you are using MinGW or this command: `cmake ..` if you are using Visual Studio

Next, if you are using MinGW, then simply type in `make`. If you are using Visual Studio, open up the solution in the build folder and then build the solution. Finally, you need to move the build result (I believe it is a .a file on MinGW and a .lib in Visual Studio) into the main LGF folder (where src and external are located at).

Now, run these commands to set up the build directory for LGF:
- `mkdir build`
- `cd build`

Now, move the file you moved from the freetype folder to the `build` directory.

After that, run these commands to build LGF and its dependencies:
- `cmake .. -G "MinGW Makefiles` **OR** `cmake ..`
- `make` **OR** open the solution with Visual Studio

Finally, move the .dll files with the `LuaGraphicsFramework.exe` file. Now, you are ready to use LGF. Again, the CLI makes this a lot easier.

### **Linux**
On Linux, building LGF is a lot easier. Enter the following commands:
- `sudo apt install libfreetype-dev cmake make gcc g++ -y` - These are Debian/Ubuntu instructions; translate to your Linux distro
- `git clone --recursive https://github.com/lua-graphics-framework/lgf`
- `cd lgf`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

Now you can use LGF.

## **Roadmap & Status**
I currently do not recommend using LGF for commercial projects quite yet. It is a very new library with very little features. Here is a roadmap listed below:

- [x] Core modules (window, rectangle, mouse, image, etc.)
- [x] CLI tools
- [ ] Linux support
- [ ] Packaging system
- [ ] OSX support
- [ ] Sound module
- [ ] Custom LGF renderer
- [ ] LuaJIT
- [ ] Custom underlying windowing system
