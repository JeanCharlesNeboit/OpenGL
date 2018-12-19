#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

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
};

#endif
