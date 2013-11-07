
#include "ThisRobot.h"


TOdo odometry;


int InitializeThisRobot(int argc, char *argv[]) {
  return 0;
}

int ConnectOdometry(int argc, char *argv[]) {
  return 0;
}

int ConnectLaser(int argc, char *argv[]) {
  return 0;
}

int ConnectDrive(int argc, char *argv[]) {
  return 0;
}

// This is never going to be called if we are truly running this offline. If for some reason this is run
// not in playback mode, this function wont do anything.
void GetSensation(TSense &sense) {
  return;
}


void GetOdometry(TOdo &odometry) {
  return;
}


void Drive(double speed, double turn) {
  return;
}
