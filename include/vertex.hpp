#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 textureCoordinates;
  glm::vec3 tangent;
  glm::vec3 bitangent;
};

#endif
