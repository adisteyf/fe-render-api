/**
 * contrib-msg
 * Contributor: IvanKoskov
 * Description: Main header of FilesEngine render API
 */

#ifndef FER_RENDERCORE_H
#define FER_RENDERCORE_H

/* includes */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
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

#if !defined(FER_WINDOW_MINOR) && !defined(FER_WINDOW_MAJOR)
  #define FER_WINDOW_MAJOR 4
  #define FER_WINDOW_MINOR 1
#endif

const char * fer_getVersion (void);

/* struct of API */
typedef struct fer {
  int vminor,vmajor;
  union {
    GLFWwindow * glfwwin;
    // ...
  };
} fer_t;

/* functions */
int     fer_createWindow (int32_t, int32_t, const char *);
int     fer_windowShouldClose (void);
void    fer_endDrawing (void);
int     fer_loadGlad (void);
void    fer_clear (float, float, float, float);

#endif // FER_RENDERCORE_H
