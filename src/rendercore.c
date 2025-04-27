/**
 * contrib-msg
 * Contributor: Adisteyf (adk.)
 * Description: Main file of FilesEngine render API
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include "rendercore.h"

fer_t FER_CORE = { 0 };

/* just to check work of library */
const char *
fer_getVersion (void) {
  return FER_VERSION_STRING;
}

#ifdef FER_WINDOW_GLFW
  #include "glfw_core.c"
#endif

