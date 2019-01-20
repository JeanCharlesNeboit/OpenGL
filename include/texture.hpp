#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

struct Texture {
public:
  enum class Type {
    diffuse,
    specular
  };

  unsigned int id;
  Type type;
  std::string path;

  std::string getName() {
    switch (type) {
    case Type::diffuse:
      return "texture_diffuse";
      break;
    case Type::specular:
      return "texture_specular";
      break;
    }
  }

  static unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);
};

#endif
