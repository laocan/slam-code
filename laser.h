
#include "ThisRobot.h"

// Variance of the laser measurements in Grid Squares
// These numbers are significantly larger than the actual variance
// that the laser readings give, as they represent a large number of 
// different variables, all of which are wrapped up into error in the
// laser reading (ie elevation, tilt, rotational calibration, uneven 
// surfaces, particle densities, etc.)
// Note that the variance for the high level in hierarchical slam is 
// much higher. This is due largely to the fact that the high level 
// takes into account so many more sensor readings, and must also 
// account for possible driftwithin a single iteration
#define LOW_VARIANCE (0.017 * MAP_SCALE*MAP_SCALE) 
#define HIGH_VARIANCE (0.17 * MAP_SCALE*MAP_SCALE)

// Set the maximum usuable distance for the laser range finder. This number is often less than the actual
// reliable distance for the specific LRF, because the laser casts 'scatter' at long distances.
#define MAX_SENSE_RANGE 7.95 * MAP_SCALE
