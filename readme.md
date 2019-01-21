# OpenGL
Cours de OpenGL ISIMA

## Requirements
Install these requirements before build.
```bash
sudo apt-get install build-essential
```
```bash
sudo apt-get install libx11-dev
```
```bash
sudo apt-get install xorg-dev libglu1-mesa-dev
```

## Dependencies
- glfw https://github.com/glfw/glfw.git
- glm https://github.com/assimp/assimp.git
- assimp https://github.com/g-truc/glm.git

## Clone
```bash
git clone https://github.com/JeanCharlesNeboit/OpenGL.git
git submodule init
git submodule update
```

## Build
```c++
mkdir build && cd build
cmake ..
make
```

## Run
```c++
./OpenGL_exe
```

## Commands

#### Keyboard controls 

``` text
Z -> go forward
S -> go backward
Q -> go left
D -> go right
↑ -> go up
↓ -> go down 
```

#### Mouse controls

``` text
scroll -> Zoom in/ out
moove -> horizontal and vertical movement 
```
