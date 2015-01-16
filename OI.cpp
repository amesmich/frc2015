#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	leftJoystick = new Joystick (1);
	rightJoystick = new Joystick (5);

	// Process operator interface input here.
}
