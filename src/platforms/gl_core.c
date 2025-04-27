#include <GL/gl.h>
extern fer_t FER_CORE;

int
fer_loadGlad (void)
{
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    perror("fer_createWindow,fer: Can't load GLAD.");
    return -1;
  }

  return 0;
}

void
fer_clear (float r, float g, float b, float a)
{
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
}

