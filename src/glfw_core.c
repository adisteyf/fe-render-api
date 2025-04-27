/**
 * contrib-msg
 * Contributor: Adisteyf (adk.)
 * Description: Main file of FilesEngine render API
 */

#include <GLFW/glfw3.h>
#include "rendercore.h"

extern fer_t FER_CORE;

int
fer_createWindow (int w, int h, const char * title)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

  FER_CORE.glfwwin = glfwCreateWindow(w,h,title,0,0);
  glfwMakeContextCurrent(FER_CORE.glfwwin);

  return 0;
}

int
fer_windowShouldClose (void)
{
  return glfwWindowShouldClose(FER_CORE.glfwwin);
}

void
fer_swapBuffers (void)
{
  return glfwSwapBuffers(FER_CORE.glfwwin);
}

void
fer_pollEvents (void)
{
  glfwPollEvents();
}


