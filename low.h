
#include "lowMap.h"

// When using hierarchical SLAM, LOW_DURATION defines how many iterations of the low level are 
// performed to form one iteration of the high level. Setting this value to ridiculously high 
// values can essentially turn off the hierarchical feature.
#define LOW_DURATION 40

// The function to call only once before LowSlam is called, and initializes all values.
void InitLowSlam();
// This function cleans up the memory and maps that were used by LowSlam.
void CloseLowSlam();
// The main function for performing SLAM at the low level. The first argument will return 
// whether there is still information to be processed by SLAM (set to 1). The second and third
// arguments return the corrected odometry for the time steps, and the corresponding list of
// observations. This can be used for the higher level SLAM process when using hierarchical SLAM.
void LowSlam(int &continueSlam, TPath **path, TSenseLog **obs);


