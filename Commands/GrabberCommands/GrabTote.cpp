#include "GrabTote.h"
#include "Subsystems/ActiveGrabber.h"

GrabTote::GrabTote()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (active_grabber);
}

// Called just before this Command runs the first time
void GrabTote::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GrabTote::Execute()
{
	active_grabber->active_grabber();
}

// Make this return true when this Command no longer needs to run execute()
bool GrabTote::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GrabTote::End()
{
	active_grabber->active_grabber();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabTote::Interrupted()
{
	active_grabber->active_grabber();

}
