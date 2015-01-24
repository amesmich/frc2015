#include "OI.h"
#include "Commands/SwitchDriveMode.h"

OI::OI()
{
	joystick = new Joystick (1);					// Controller connected to port 1 on the driver station

	a_button = new JoystickButton (joystick, 1);	// The 'A' button on the controller
	a_button->WhenPressed(new SwitchDriveMode());	// switch the drive's perspective
	                                                // when the button is pressed
}
