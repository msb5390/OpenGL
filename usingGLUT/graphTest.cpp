// graphTest.cpp
//
// This program is my first attempt to do graphics in c++ on a mac.
//
// Written by Michael S. Bell
// msb5390@gmail.com
// March 08, 2017

#include <iostream>
//#include "../include/math/miscmath.h"
#include <GLUT/GLUT.h>
//#include <OpenGL/OpenGL.h>
//#include <OpenGL/glu.h>
//#include <vector>

using namespace std;

// Create a function to initialize everything:
void display(void)
{
  // Clear the color buffer.
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0,0.0,0.0);

  // Let us begin drawing some points.
  glBegin(GL_POLYGON);
  // Specify the points.
  glVertex3f(2.0, 4.0, 0.0);
  glVertex3f(8.0, 4.0, -1.0);
  glVertex3f(8.0, 6.0, 1.0);
  glVertex3f(2.0, 6.0, 0.0);
  // Ok, done specifying points.
  glEnd();

  // Write this to the screen.
  glFlush();
}

int main(int argc, char **argv)
{
  // Init glut passing some args from main.
  glutInit(&argc, argv);

  // Specify the display mode. Here we are specifying that there
  // is a single buffer and we're using RGB to specify colors.
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_RGB);

  // Say where to place the window initially.
  glutInitWindowPosition(100,100);

  // Set the window size.
  glutInitWindowSize(300, 300);

  // Name the window and create it.
  glutCreateWindow("My First Window");
  
  // White background
  glClearColor(1.0, 1.0, 1.0, 1.0);

  // Set up viewing projection
  glMatrixMode(GL_PROJECTION);

  // Start with identity matrix.
  glLoadIdentity();

  // Set up a 10x10x2 viewing world.
  glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);

  // Set the callback function, which will be called as needed.
  glutDisplayFunc(display);

  // Start the main loop running. Nothing after this will execute for all
  // eternity.
  glutMainLoop();

  return 0;
}
