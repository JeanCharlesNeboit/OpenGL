# OpenGL
Cours de OpenGL ISIMA

## Requirements
Install these requirements before build.

- OpenGL3
- g++
- cmake


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

/!\ Your mouse is catched in the window but allows you to moove in the scene, be careful to watch everywher for the objects.

#### Keyboard controls 

``` text
esc -> exit
1/& -> brightness up
2/é -> brightness down
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
## Architecture

### UML
![alt text](https://github.com/JeanCharlesNeboit/OpenGL/blob/develop/UML.jpg)

### Explications

Pour réaliser ce TP d'OpenGL nous avons décidés d'utiliser la version d'OpenGL 3.
En effet, depuis cette version, OpenGL contient à la fois les Shader (Vertex et Fragment) ainsi que les VAO et VBO.
Nous avons aussi décidés d'utiliser plusieurs librairies, la première étant la bibliothèque d'OpenGL, GLFW, permettant d'offrir un jeu de routing
pour la gestion des fenêtres OpenGL. Nous avons aussi utilisés GLM, qui est une bibliothèque mathématique pour OpenGL, ainsi que
assimp qui est une bibliothèque d'importation de modèle 3D. Ainsi, l'architecture de notre application est étroitement liée aux solutions techniques
que nous avons sélectionnées. En effet, pour développer une application OpenGL il est necessaire d'utiliser des Shader qui sont des programmes exécutés par le GPU.
Chaque Shader est composé **a minima** d'un Vertex Shader et d'un Fragment Shader, et doit être compilé avant d'être éxécuté par le GPU.
Nous avons donc créé une classe Shader nous permettant de créé les programmes qui vont être éxécutés par le GPU. Nous avons aussi créé une classe
camera nous permettant de visualiser la scene 3D en nous renvoyant la matrice de vue (getViewMatrix). De plus, les classes Model, Mesh, Texture et Vertex
sont des classes qui nous permettent de modéliser les objets 3D affiché avec assimp. Chaque modèle 3D (classe Model) est composé de plusieurs
Mesh et Texture et chaque Mesh est composé de vertices et textures. Pour afficher l'objet, il suffit de lier celui ci à son programme OpenGL (Shader)
ce qui est le rôle de la fonction draw.

### Résultats
![alt text](https://github.com/JeanCharlesNeboit/OpenGL/blob/develop/Results.png)

Nous avons donc une scene avec deux partie, à droite nous avons des cubes affichés sans la librairie assimp, c'est à dire que nous avons placé nous même les vertices.
A gauche, nous avons un modèle 3D chargé avec assimp, c'est à dire qu'il a été précedement réalisé avec un logiciel de modélisation 3D tel que Blender. Seule la partie de droite
est éclairé grâce à un éclairage ambiant réglable (é/2 -> +, 1&/ -> -). Nous n'avons pas eu le temps de faire un éclairage diffus ou spéculaire.
