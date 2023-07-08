# A Simple Physics Engine Using GLFW, OpenGL, and Glad

As the title states, this is a simple physics engine. This project was done as a means to learn how physics engines are created and how they work. This project was done on Windows machine.

## Getting Started

It's required that you have the following installed:
- [Visual Studio](https://visualstudio.microsoft.com/)
- [CMake](https://cmake.org/download/) (highly recommeneded for compiling the pre-compiled binaries so they are tailored to your system)
- 
Download the source package for [GLFW](https://www.glfw.org/download.html) and [Glad](https://www.glfw.org/download.html). For Glad, make sure that C/C++ is selected along with version 3.3 and that you select Core as the profile. The GLFW library allows us to interact with OpenGL drivers and provide us with the tools needed to do render objects in a window. We use Glad as a tool to fetch the functions of an OpenGL driver at runtime (we don't know where these function are beforehand since there are different implementations of OpenGL).
