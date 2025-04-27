/**
 * contrib-msg
 * Contributor: IvanKoskov
 * Description: Main header of FilesEngine render API
 */

#ifndef FER_RENDERCORE_H
#define FER_RENDERCORE_H

/* includes */
#include <GLFW/glfw3.h>
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
  union {
    GLFWwindow * glfwwin;
    // ...
  };
} fer_t;

/* functions */
int     fer_createWindow (int32_t, int32_t, const char *);
int     fer_windowShouldClose (void);
void    fer_swapBuffers (void);
void    fer_pollEvents (void);


#endif // FER_RENDERCORE_H
