#include "ActiveGrabber.h"
#include "Commands/GrabberCommands/GrabTote.h"
#include "../RobotMap.h"

ActiveGrabber::ActiveGrabber(): Subsystem("Active Grabber")
{
	left_grabber = new CANTalon(21);
	right_grabber = new CANTalon(22);

	is_default_mode = false;
}

void ActiveGrabber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand (new GrabTote());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ActiveGrabber::active_grabber()
{
	if (this->is_default_mode)
	{
		if(!(this->is_right_motor_stalled() && this->is_left_motor_stalled()))
		{
			this->spin_motors_out();
		}
		else
		{
			right_grabber->Set(0.0);
			left_grabber->Set(0.0);
		}
	}
}

void ActiveGrabber::spin_motors_in()
{
	right_grabber->Set(.75 * .5);
	left_grabber->Set(.75 * -.5);
}

void ActiveGrabber::spin_motors_out()
{
	right_grabber->Set(.75 * .25);
	left_grabber->Set(.75 * -.25);
}

bool ActiveGrabber::is_left_motor_stalled()
{
	if (left_grabber->GetOutputCurrent() > 0.5)
	{
		return true;
	}
	return false;
}

bool ActiveGrabber::is_right_motor_stalled()
{
	if (right_grabber->GetOutputCurrent() > 0.5)
	{
		return true;
	}
	return false;
}

void ActiveGrabber::update_status()
{
	//TODO this shit
}

void ActiveGrabber::switch_grabber_mode()
{
	is_default_mode = !is_default_mode;
}

void ActiveGrabber::set_grabber_mode_default()
{
	is_default_mode = false;
}

bool ActiveGrabber::get_grabber_mode()
{
	return is_default_mode;
}

