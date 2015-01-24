#include "AutoLeft.h"

AutoLeft::AutoLeft()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

  Requires(drivetrain);
}

// Called just before this Command runs the first time
void AutoLeft::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoLeft::Execute()
{
  drivetrain->mecanum_drive(-SLOW_SPEED, 0.0, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeft::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoLeft::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeft::Interrupted()
{

}
