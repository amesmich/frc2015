#include "AutoRight.h"

AutoRight::AutoRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

  Requires(drivetrain);
}

// Called just before this Command runs the first time
void AutoRight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoRight::Execute()
{
  drivetrain->mecanum_drive(SLOW_SPEED, 0.0, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoRight::End()
{
  drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRight::Interrupted()
{
  drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}
