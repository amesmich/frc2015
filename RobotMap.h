#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

//Drivetrain Constants
const float SLOW_SPEED = 0.25;  //Speed for slow-moving autonomous commands
const float MID_SPEED = 0.50;   //Speed for moderately-moving autonomous commands
const float HIGH_SPEED = 0.75;  //Speed for fast-moving autonomous commands
const float MAX_SPEED = 0.50;   //Speed limit multiplier for motors

//OI Constants
const int DRIVER_CONTROLLER_PORT = 1;

const int A_BUTTON = 1;
// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
