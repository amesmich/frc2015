#include "SwitchGrabberMode.h"
#include "Subsystems/ActiveGrabber.h"

SwitchGrabberMode::SwitchGrabberMode()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (active_grabber);
}

// Called just before this Command runs the first time
void SwitchGrabberMode::Initialize()
{
	active_grabber->switch_grabber_mode();
}

// Called repeatedly when this Command is scheduled to run
void SwitchGrabberMode::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SwitchGrabberMode::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SwitchGrabberMode::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchGrabberMode::Interrupted()
{

}
