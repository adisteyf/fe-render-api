/**
 * contrib-msg
 * Contributor: Adisteyf (adk.)
 * Description: Main file of FilesEngine render API
 */

#include <GLFW/glfw3.h>
#include <stdio.h>
extern fer_t FER_CORE;

int
fer_createWindow (int w, int h, const char * title)
{
  FER_CORE.vmajor = FER_WINDOW_MAJOR;
  FER_CORE.vminor = FER_WINDOW_MINOR;

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, FER_CORE.vmajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, FER_CORE.vminor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

  FER_CORE.glfwwin = glfwCreateWindow(w,h,title,0,0);
  glfwMakeContextCurrent(FER_CORE.glfwwin);
  fer_loadGlad();

  return 0;
}

int
fer_windowShouldClose (void)
{
  return glfwWindowShouldClose(FER_CORE.glfwwin);
}

void
fer_beginDrawing (void)
{
  /* TODO: fill this function */
  return;
}

void
fer_endDrawing (void)
{
  glfwSwapBuffers(FER_CORE.glfwwin);
  glfwPollEvents();
}
