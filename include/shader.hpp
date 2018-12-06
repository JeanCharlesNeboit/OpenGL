#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
  unsigned int ID;
public:
  Shader(const GLchar* vertexPath, const GLchar* framentPath);
  void use();
  void setBool(const std::string & name, bool value) const;
  void setFloat(const std::string & name, float value) const;
  void setInt(const std::string & name, int value) const;
  unsigned int getID() { return ID; }
};

#endif
