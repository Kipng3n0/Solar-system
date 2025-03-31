# SolarSystemOpenGL


Planets and sun are not to real scale or distances. Rendering distance would need to be huge for that. Currently They are on Multiples of the actual distance.

C++ and GLSL are the main programming languages of this project.


## How to render

The following guide is for Ubuntu 18.04 (possibly 20.04) and it's variants (Xubuntu, Lubuntu, etc...). There are also a [Windows version]
First make sure that you have all the required dependencies installed. To install them, run the following command:

`sudo apt-get install make libglu1-mesa-dev freeglut3-dev mesa-common-dev libglfw3 libglfw3-dev libglew-dev libglm-dev libsdl2-dev binutils-gold g++ mesa-common-dev build-essential libglew1.5-dev libglm-dev `



Secondly, compile! To do such, on the top of the directory, type:

`make`

This will create an executable named solarSystem in the main directory and automatically execute it.

Now, wait, as depending on your machine it can take a bit to open. Use WASD to move, the mouse to look around and shift key to move faster. The camera is above the sun, so if you only see stars, look down first to see the sun, then you can locate the planets! 

To build the executable file, just type:

`make build`

This will not run automatically the program. Like this, you can afterwards run it via `./solarSystem`, or transfer to another machine and execute it there, and use the same command. The executable file is named `solarSystem`.

There is also a rule in the Makefile to clean the output of the compilation, for a clean build:

`make clean`

For better organization, there will be added in future an output directory, to keep the executable.



