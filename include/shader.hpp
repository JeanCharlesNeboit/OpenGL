#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
  unsigned int ID;
public:
  Shader();
  Shader(const GLchar* vertexPath, const GLchar* framentPath);
  void use();
  void setBool(const std::string & name, bool value) const;
  void setFloat(const std::string & name, float value) const;
  void setInt(const std::string & name, int value) const;
  void setMat4(const std::string &name, const glm::mat4 &mat) const;
  void setVec3(const std::string &name, const glm::vec3 &value) const;
  unsigned int getID() { return ID; }
};

#endif
