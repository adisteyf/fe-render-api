#include "rendercore.h"
#include <stdlib.h>

int
main (void)
{
  const char * result = fer_getVersion();
  printf("%s\n", result);

  fer_t * testapi = fer_init(1,1,4,1);
  printf("GPU API: %d\nWINDOW API: %d\n", testapi->render_api, testapi->window_api);

  fer_createWindow(testapi,800,600,"title");
  system("read");

  fer_free(testapi);
  return 0;
}
