
#include "basic.h"

// The number of sensor readings for this robot (typically 181 for a laser range finder)
#define SENSE_NUMBER 180
// Turn radius of the robot in map squares.Since the "robot" is actually the sensor origin for the
// purposes of this program, the turn radius is the displacement of the sensor from the robot's center
// of rotation (assuming holonomic turns)
#define TURN_RADIUS (0.40 * MAP_SCALE)

// Each sensor reading has direction it is looking (theta) and a distance at which it senses the object.
// Direction of the sensor is relative to the facing of the robot, with "forward" being 0, and is
// measured in radians. 
struct TSense_struct{
  double theta, distance;
};
typedef struct TSense_struct TSenseSample;
typedef TSenseSample TSense[SENSE_NUMBER+1];

// This is the structure for storing odometry data from the robot. The same conditions apply as above.
struct odo_struct{
  double x, y, theta;
};
typedef struct odo_struct TOdo;

extern TOdo odometry;


int InitializeThisRobot(int argc, char *argv[]);
int ConnectOdometry(int argc, char *argv[]);
int ConnectLaser(int argc, char *argv[]);
int ConnectDrive(int argc, char *argv[]);
void GetSensation(TSense &sense);
void GetOdometry(TOdo &odometry);
void Drive(double speed, double turn);
