#include "rendercore.h"
#include <glad/glad.h>

int
main (void)
{
  fer_createWindow(800,600,"title");

  for (;!fer_windowShouldClose();) {
    fer_beginDrawing();
    fer_clear(1.f, 1.f, 1.f, 1.f);
    fer_endDrawing();
  }

  return 0;
}
