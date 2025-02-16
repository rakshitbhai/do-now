// colors.h
#ifndef COLORS_H
#define COLORS_H
#include <stdarg.h> // Required for variable arguments

// Function prototypes
void error(const char *message);
void success(const char *format, ...);
void normal(const char *format, ...);
void normalMag(const char *format, ...);
void speed(const char *format, ...);

#endif
