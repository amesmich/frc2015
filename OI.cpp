#include "OI.h"
#include "RobotMap.h"
#include "Commands/SwitchDriveMode.h"
#include "Commands/GrabberCommands/SwitchGrabberMode.h"

OI::OI()
{
	joystick = new Joystick (DRIVER_CONTROLLER_PORT);	// Controller connected to port 1 on the driver station

	a_button = new JoystickButton (joystick, A_BUTTON);	// The 'A' button on the controller
	a_button->WhenPressed(new SwitchDriveMode());		// switch the drive's perspective
	                                                	// when the button is pressed

	b_button = new JoystickButton (joystick, B_BUTTON);
	x_button = new JoystickButton (joystick, X_BUTTON);

	y_button = new JoystickButton (joystick, Y_BUTTON);
	y_button->WhenPressed(new SwitchGrabberMode());
}

