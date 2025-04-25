//
// rendercore.h
//
// Created by Ivan Koskov on Fri 25 Apr 2025
//
// Contributors
//

#pragma once
#ifndef FER_RENDERCORE_H
#define FER_RENDERCORE_H


#if defined(_WIN32) || defined(__WIN32__) || defined(__NT__) // Windows (32-bit and 64-bit)
    #ifdef _WIN64
        // Windows 64
    #else
        // Windows 32
    #endif
#elif defined(__APPLE__) // macOS

#include <stdio.h>


#elif defined(__linux__) // Linux

#include <stdio.h>

#elif defined(__FreeBSD__) // FreeBSD
    
#else
    #error "Unsupported platform"
#endif

// Universal
#define FER_TRUE 1
#define FER_FALSE 0






#endif // FER_RENDERCORE_H