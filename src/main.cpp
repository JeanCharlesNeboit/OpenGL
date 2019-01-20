#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "scene/scene.hpp"
#include "scene/mainscene.hpp"
#include "filesystem.hpp"

// Function called when window size changes.
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
// Function called when a error occurs.
void error_callback(int error, const char *description);
// Function called when mouse moves.
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
// Function called when user scrolls.
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

// Default size of the window
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// The displayed scene pointer.
Scene* scene;

int main()
{
    // Initialization of OpenGL
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    glfwSetErrorCallback(error_callback);

    // Creation of the OpenGL window
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Link OpenGL events to callbacks functions
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // tell GLFW to capture the mouse

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Configure th global OpenGL state
    glEnable(GL_DEPTH_TEST);

    // Frame computing
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // Instanciation of the scene
    scene = new MainScene();

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
      // per-frame time logic
      float currentFrame = glfwGetTime();
      deltaTime = currentFrame - lastFrame;
      lastFrame = currentFrame;

      // Display scene
      scene->display(window, SCR_WIDTH, SCR_HEIGHT, deltaTime);
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void error_callback(int error, const char *description)
{
    puts(description);
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
  scene->mouse_callback(window, xpos, ypos);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  scene->scroll_callback(window, xoffset, yoffset);
}
