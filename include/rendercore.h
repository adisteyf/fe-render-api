/**
 * contrib-msg
 * Contributor: IvanKoskov
 * Description: Main header of FilesEngine render API
 */

#ifndef FER_RENDERCORE_H
#define FER_RENDERCORE_H

/* includes */
#include <stdint.h>


#if defined(_WIN32) || defined(__WIN32__) || defined(__NT__) /* W*ndows */
    #ifdef _WIN64
    #define FER_PLATFORM WINDOWS_64
    #else
    #define FER_PLATFORM WINDOWS_32
    #endif
#elif defined(__APPLE__) /* macOS */
    #define FER_PLATFORM MACOS
    #include <stdio.h>
#elif defined(__linux__) /* Linux */
    #define FER_PLATFORM LINUX
    #include <stdio.h>
#elif defined(__FreeBSD__) /* FreeBSD */
    #define FER_PLATFORM FREEBSD
#else
    #error "Unsupported platform"
#endif

/* Universal */
#define FER_VERSION_MAJOR  1
#define FER_VERSION_MINOR  0

#define __FER_NUMTOSTR(n) #n
#define __FER_DEFTOSTR(def) __FER_NUMTOSTR(def)
#define FER_VERSION_STRING __FER_DEFTOSTR(FER_VERSION_MAJOR) "." __FER_DEFTOSTR(FER_VERSION_MINOR)

#define FER_API __attribute__((visibility("default")))
const char * fer_getVersion (void);

/* Graphics APIs */
#define FER_OPENGL 1
#define FER_GLFW   1

/* struct of API */
typedef struct fer {
  int32_t   render_api;
  int32_t   window_api;
  int32_t   vminor;
  int32_t   vmajor;
  void    * mainwin;
} fer_t;

/* functions */
fer_t * fer_init (int32_t, int32_t, int32_t, int32_t);
void    fer_free (fer_t *);
int     fer_createWindow (fer_t *, int32_t, int32_t, const char *);
int     fer_windowShouldClose (fer_t *);
int     fer_swapBuffers (fer_t *);
int     fer_pollEvents (fer_t *);


#endif // FER_RENDERCORE_H
