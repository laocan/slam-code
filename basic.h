
// These includes pull in interface definitions and utilities.
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// This defines the number of grid squares per meter. 
// All sensors are assumed to be measuring in meters, whereas all code uses a basic unit of grid squares. 
// We use this constant for conversion.
#define MAP_SCALE 35

// Some useful macros
#define SIGN(A) ((A) >= 0.0 ? (1.0) : (-1.0))
#define SQUARE(A) (((A) * (A)))
#define MAX(A,B) ((A) >= (B) ? (A) : (B))
#define MIN(A,B) ((A) >= (B) ? (B) : (A))

// An approximation of a normal distribution, where A is the standard deviation
#define GAUSSIAN(A) ((MTrandDec()+MTrandDec()+MTrandDec()+MTrandDec()+MTrandDec()+MTrandDec()-3)*(A)/.7071)

#define FALSE 0
#define TRUE 1

// When recording a log file, the file name of the log is stored in *RECORDING
// When playing back a log file, the name is stored in *PLAYBACK
extern char *PLAYBACK, *RECORDING;
