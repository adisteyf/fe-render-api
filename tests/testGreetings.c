#define FER_WINDOW_GLFW
#include "rendercore.h"
#include <stdlib.h>

int
main (void)
{
  const char * result = fer_getVersion();
  printf("%s\n", result);

  /*printf("GPU API: %d\nWINDOW API: %d\n", testapi->render_api, testapi->window_api);

  fer_createWindow(testapi,800,600,"title");
*/
  fer_createWindow(800,600,"title");

  for (;!fer_windowShouldClose();) {
    fer_swapBuffers();
    fer_pollEvents();
  }

  return 0;
}
