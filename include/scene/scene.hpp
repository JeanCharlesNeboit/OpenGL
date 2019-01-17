#ifndef SCENE_HPP
#define SCENE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Scene {
public:
  virtual void display(GLFWwindow *window, unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT, float) = 0;
  virtual void mouse_callback(GLFWwindow *window, double xpos, double ypos) = 0;
  virtual void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) = 0;
};

#endif
