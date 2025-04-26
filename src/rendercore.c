/**
 * contrib-msg
 * Contributor: Adisteyf (adk.)
 * Description: Main file of FilesEngine render API
 */

#include <stdlib.h>
#include <stdint.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include "rendercore.h"


/* just to check work of library */
const char *
fer_getVersion (void) {
  return FER_VERSION_STRING;
}

fer_t *
fer_init (int32_t render_api, int32_t window_api, int32_t vminor, int32_t vmajor)
{
  fer_t * ret = malloc(sizeof(fer_t));
  ret->render_api = render_api;
  ret->window_api = window_api;
  ret->vminor     = vminor;
  ret->vmajor     = vmajor;

  //static int32_t isGlfwInitCalled = 1;
  switch (ret->window_api) {
  case FER_GLFW:
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, vminor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, vmajor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    break;
  default:
    printf("FE_RENDER_API,fer_init: UNKNOWN window_api\n");
    free(ret);
    return 0;
  }

  return ret;
}

int
fer_createWindow (fer_t * fer, int32_t w, int32_t h, const char * title)
{
  if (!fer) {
    printf("FE_RENDER_API,fer_createWindow: Can't create window. fer == NULL\n");
    return 1;
  }

  switch (fer->window_api) {
  case FER_GLFW:
    fer->mainwin = (void *)glfwCreateWindow(w,h,title,0,0);
    glfwMakeContextCurrent((GLFWwindow *)fer->mainwin);
    return 0;
  default:
    printf("FE_RENDER_API,fer_createWindow: UNKNOWN window_api\n");
    return 2;
  }
}

int
fer_windowShouldClose (fer_t * fer)
{
  switch (fer->window_api) {
  case FER_GLFW:
      return glfwWindowShouldClose((GLFWwindow *)fer->mainwin);
  default:
    printf("FE_RENDER_API,fer_windowShouldClose: UNKNOWN window_api\n");
    return -1;
  }
}

int
fer_swapBuffers (fer_t * fer)
{
  switch (fer->window_api) {
  case FER_GLFW:
    glfwSwapBuffers((GLFWwindow *)fer->mainwin);
    return 0;

  default:
    printf("FE_RENDER_API,fer_windowShouldClose: UNKNOWN window_api\n");
    return -1;
  }
}

int
fer_pollEvents (fer_t * fer)
{
  switch (fer->window_api) {
  case FER_GLFW:
    glfwPollEvents();
    return 0;
  default:
    printf("FE_RENDER_API,fer_windowShouldClose: UNKNOWN window_api\n");
    return -1;
  }
}

void
fer_free (fer_t * fer) {
  switch (fer->window_api) {
  case FER_GLFW:
    glfwTerminate();
  default:
    printf("FE_RENDER_API,fer_free(): UNKNOWN window_api\n");
  }
  free(fer);
}
