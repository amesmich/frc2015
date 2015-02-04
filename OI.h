#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"

class OI
{
private:

public:
	OI();

	Joystick *joystick;		// The controller for the robot
	JoystickButton *a_button;	// The 'A' button on the controller
	JoystickButton *y_button; // The 'Y' button on the controller
};

#endif
