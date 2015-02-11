#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

public:
	OI();

	Joystick *joystick;				// The controller for the robot

	JoystickButton *a_button;		// The 'A' button on the controller

	JoystickButton *b_button;	// 'b' on the controller
	JoystickButton *x_button;	// 'x' on the controller

	JoystickButton *y_button;  // y button on the controller
};

#endif
