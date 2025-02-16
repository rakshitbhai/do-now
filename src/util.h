#ifndef UTIL_H
#define UTIL_H

#include <time.h>

// Declare global variables
extern char true;
extern char false;
extern char weekDay[6];
extern char month[5];
extern char day[4];
extern char year[6];
extern char *baseDir;

// Declare functions
void startCount();
void initialize();
void interrupt();
void getUserList();
void generate();
void endCount();
#endif // UTIL_H
