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

const int FRONT_LEFT_MOTOR = 1;
const int FRONT_RIGHT_MOTOR = 2;
const int BACK_LEFT_MOTOR = 3;
const int BACK_RIGHT_MOTOR = 4;


//OI Constants
const int DRIVER_CONTROLLER_PORT = 1;

const int A_BUTTON = 1;             //A button
const int B_BUTTON = 2;             //B Button
const int X_BUTTON = 3;             //X Button
const int Y_BUTTON = 4;             //Y Button

const int LEFT_BUTTON = 5;          //Left Button (considered an axis)
const int RIGHT_BUTTON = 6;         //Right Button (considered an axis)
const int LEFT_TRIGGER = 2;         //Left Trigger
const int RIGHT_TRIGGER = 3;        //Right Trigger

const int LEFT_STICK_X_AXIS = 0;    //X-axis of the Left Stick
const int LEFT_STICK_Y_AXIS = 1;    //Y-axis of Left Stick
const int LEFT_STICK_BUTTON = 9;    //Button when pressing down Left Stick

const int RIGHT_STICK_X_AXIS = 4;   //X-Axis of Right Stick
const int LEFT_STICK_Y_AXIS = 5;    //Y-Axis of Right Stick
const int RIGHT_STICK_BUTTON = 10;  //Button when pressing down Right Stick

const int BACK_BUTTON = 7;          //Back Button (in middle of controller)
const int START_BUTTON = 8;         //Start Button (in middle of controller)

//Consider this PDF if you are unsure of where the buttons on the controller are.
//http://team358.org/files/programming/ControlSystem2015-2019/images/Logitech-F310_ControlMapping.pdf

//ActiveGrabber Constants
const int LEFT_GRABBER_MOTOR = 21;    //Left motor of ActiveGrabber
const int RIGHT_GRABBER_MOTOR = 22;   //Right motor of ActiveGrabber


// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;


#endif
