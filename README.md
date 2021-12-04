# SudoCraft
This is a prototype game that I am creating.
At this moment in time it is supposed to be a 2D dungeon crawler Minecrfat type game.

This game is being made in C++

# Building & Installing
## Linux
To build Sudocraft in Linux, you need [Make](https://www.gnu.org/software/make/) or [CMake](https://cmake.org/download/). To build, run: 
```
mkdir build && cd build
../configure
make && make install
```
or:
```
mkdir build && cd build
cmake ..
make && make install
```
To install to your user account or locally, run:
```
mkdir build && cd build
../configure --prefix= your/install/path
make && make install
```
or:
```
mkdir build && cd build
CMAKE_INSTALL_PREFIX = your/install/path/
cmake ..
make && make install
``` 

## Windows
### Visual Studio's Project
To build Sudocraft in Windows using Microsoft Visual Studio's, you need [CMake](https://cmake.org/download/) and [Microsoft Visual Studio's](https://visualstudio.microsoft.com/) installed. To install, run:
```
mkdir build && cd build
cmake .. -G "Visual Studios 16 2019 Win64"
```
Then open the solution file (.sln file extention) or build from the command line by using:
```
cmake --build .
```
After making the solution file.
### CLang with Visual Studio's
To build Sudocraft in Windows using CLang, you need [CLang](https://clang.llvm.org/get_started.html), [CMake](https://cmake.org/download/), [Microsoft Visual Studio's](https://visualstudio.microsoft.com/), [Python](https://www.python.org/download/), and [GNUWin32 Tools](http://getgnuwin32.sourceforge.net/) installed. To install, run:
```
cmake .. -G "Visual Studios 16 2019 Win64" -T "ClangCL"
cmake --build .
```
# Running
In the command line, run `sudocraft`.
