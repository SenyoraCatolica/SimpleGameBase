#pragma once

#include <Windows.h>
#include <stdio.h>

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};


//Typedefs================================
typedef unsigned int uint;



//Defines=================================

#define RELEASE(x) \
    { \
    if (x != nullptr) \
      delete x; \
	x = nullptr; \
	} \

#define RELEASE_ARRAY(x) \
    { \
    if (x != nullptr) \
      delete[] x; \
	x = nullptr; \
	} \


#define MAX_BUF_SIZE 4096
#define OPEN_GL_BUF_SIZE 512
#define DEFAULT_BUF_SIZE 256
#define INPUT_BUF_SIZE 128

#define CAP(n) ((n <= 0.0f) ? n=0.0f : (n >= 1.0f) ? n=1.0f : n=n)

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

#define MSTOSECONDS 0.001



//Log system==============================

#define CONSOLE_LOG(format, ...) Log(__FILE__, __LINE__, format, __VA_ARGS__);

void Log(const char file[], int line, const char* format, ...);
