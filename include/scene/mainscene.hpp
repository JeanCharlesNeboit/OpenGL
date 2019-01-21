#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP

#include "scene/scene.hpp"
#include "shader.hpp"
#include "camera.hpp"
#include <vector>
#include "mesh.hpp"
#include "model.hpp"

class MainScene: public Scene {
private:
  // camera
  Camera camera;

  bool firstMouse = true;
  float yaw = -90.0f; // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
  float pitch = 0.0f;
  float lastX = 800.0f / 2.0;
  float lastY = 600.0 / 2.0;
  float fov = 45.0f;

  // shaders
  Shader cubeShader;
  Shader modelShader;
  
  // meshes
  std::vector<Mesh> meshes;

  // models
  Model model;

  // VAO, VBO
  unsigned int cubeVBO, cubeVAO;

  // textures
  unsigned int texture1, texture2;

  // lights
  glm::vec3 ambientLightColor;

public:
  MainScene();
  ~MainScene();
  void display(GLFWwindow *window, unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT, float deltaTime) override;
  void mouse_callback(GLFWwindow *window, double xpos, double ypos) override;
  void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) override;
  void processInput(GLFWwindow *window, float deltaTime);
};

#endif
