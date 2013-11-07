

#include "map.h"

// The global map used by the low level slam process. These are pointers to MapStarter in order
// to save memory on te large amount of unobserved grid squares.
extern PMapStarter lowMap[MAP_WIDTH][MAP_HEIGHT];
// The nodes of the ancestry tree are stored here. Since each particle has a unique ID, we can 
// quickly access the particles via their ID in this array. See the structure TAncestor in map.h 
// for more details.
extern TAncestor l_particleID[ID_NUMBER];

// Our current set of particles being processed by the particle filter
extern TParticle l_particle[PARTICLE_NUMBER];
// We like to keep track of exactly how many particles we are currently using.
extern int l_cur_particles_used;


void LowInitializeFlags();
void LowInitializeWorldMap();
void LowDestroyMap();
void LowResizeArray(TMapStarter *node, int deadID);
void LowDeleteObservation(short int x, short int y, short int node);
double LowComputeProb(int x, int y, double distance, int ID);

void LowAddTrace(double startx, double starty, double MeasuredDist, double theta, int parentID, int addEnd);
double LowLineTrace(double startx, double starty, double theta, double MeasuredDist, int parentID, float culling);
