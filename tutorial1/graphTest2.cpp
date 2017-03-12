// graphTest2.cpp
//
// This program is my attempt to use a different window API than GLUT.
// Apparently that one has been deprecated (the compiler complains with
// some warnings about it), so I'm using glfw instead.
//
// Written by Michael S. Bell
// msb5390@gmail.com
// March 11, 2017

// Standard library includes:
#include <iostream>

// Graphics includes:
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Include GLM for some math stuff.
//#include <glm/glm.hpp>
//using namespace glm;

int main(){

  // Initialize GLFW
  if (!glfwInit())
    {
      fprintf( stderr, "Failed to initialize GLFW\n");
      return -1;
    }

  // 4x antialiasing?
  glfwWindowHint(GLFW_SAMPLES, 4); 
  // Use OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // To make MacOS happy; should not be needed.
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
  // Don't use the old OpenGL
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
  
  // Open a window and create its OpenGL context.
  GLFWwindow* window;
  window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
  if (window == NULL){
    fprintf(stderr, "Failed to open GLFW windo. If you have an Intel GPU, they are not 3.3 compatible. Trye the 2.1 version of the tutorials.\n");
    glfwTerminate();
    return -1;
  }
  // Initialize GLEW.
  glfwMakeContextCurrent(window);
  // Needed in core profile.
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }

  // Ensure we can capture the escape key being pressed below.
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  do{

    // Draw nothing, see you in tutorial 2!

    // Swap buffers.
    glfwSwapBuffers(window);
    glfwPollEvents();
  } // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	 glfwWindowShouldClose(window) == 0);
  return 1;
}
