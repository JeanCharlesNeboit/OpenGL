#include "mesh.hpp"

Mesh::Mesh(std::vector<Vertex>& _vertices, std::vector<unsigned int>& _indices, std::vector<Texture>& _textures) :
  vertices(_vertices), indices(_indices), textures(_textures) {
  setupMesh();
}

void Mesh::draw(Shader shader) {
  unsigned int diffuseNormal = 1;
  unsigned int specularNormal = 1;
  for(unsigned int i = 0; i < textures.size(); ++i) {
    glActiveTexture(GL_TEXTURE0 + i);
    std::string number;
    Texture::Type type = textures[i].type;
    std::string name = textures[i].getName();
    if(type == Texture::Type::diffuse) {
      number = std::to_string(diffuseNormal++);
    }
    else if(type == Texture::Type::specular) {
      number = std::to_string(specularNormal++);
    }
    glUniform1i(glGetUniformLocation(shader.getID(), (name + number).c_str()), i);
    glBindTexture(GL_TEXTURE_2D, textures[i].id);
  }

  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES,indices.size(), GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);

  glActiveTexture(GL_TEXTURE0);
}

void Mesh::setupMesh() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoordinates));

  glBindVertexArray(0);
}
