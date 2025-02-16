// colors.c
#include <stdio.h>
#include "colors.h"

// Escape codes
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define WHITE_TEXT "\033[37m"
#define BLACK_BG "\033[40m"
#define BLUE "\033[34m"
#define RESET "\033[0m" // Reset to default color
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

// Function to print error messages (red text on black background)
void error(const char *message)
{
    printf(RED_TEXT "%s" RESET, message);
}

// Function to print success messages (green text on black background)
void success(const char *format, ...)
{
    va_list args;

    // Set the text color to green and background to black
    printf(GREEN_TEXT);

    // Start processing the variable arguments
    va_start(args, format);

    // Print the formatted message (like printf)
    vprintf(format, args);

    // Clean up the va_list
    va_end(args);

    // Reset the color to default
    printf(RESET);
}

// Function to print normal messages (white text on black background)
void normal(const char *format, ...)
{
    va_list args;

    // Set the text color to white and background to black
    printf(WHITE_TEXT);

    // Start processing the variable arguments
    va_start(args, format);

    // Print the formatted message (like printf)
    vprintf(format, args);

    // Clean up the va_list
    va_end(args);

    // Reset the color to default
    printf(RESET);
}

void normalMag(const char *format, ...)
{
    va_list args;

    // Set the text color to white and background to black
    printf(MAGENTA);

    // Start processing the variable arguments
    va_start(args, format);

    // Print the formatted message (like printf)
    vprintf(format, args);

    // Clean up the va_list
    va_end(args);

    // Reset the color to default
    printf(RESET);
}

void speed(const char *format, ...)
{
    va_list args;

    // Set the text color to green and background to black
    printf(BLUE);

    // Start processing the variable arguments
    va_start(args, format);

    // Print the formatted message (like printf)
    vprintf(format, args);

    // Clean up the va_list
    va_end(args);

    // Reset the color to default
    printf(RESET);
}