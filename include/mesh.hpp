#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include "vertex.hpp"
#include "texture.hpp"
#include "shader.hpp"

class Mesh {
private:
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<Texture> textures;

  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;

  void setupMesh();

public:
  Mesh(std::vector<Vertex>&, std::vector<unsigned int>&, std::vector<Texture>&);
  void draw(Shader);
};

#endif
