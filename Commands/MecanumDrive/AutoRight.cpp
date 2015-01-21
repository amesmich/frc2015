#include "AutoForward.h"

AutoForward::AutoForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
  Requires (drivetrain);
}

// Called just before this Command runs the first time
void AutoForward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoForward::Execute()
{
  drivetrain->mecanum_drive(0.0, 0.85, 0.0); //TODO set default value
}

// Make this return true when this Command no longer needs to run execute()
bool AutoForward::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoForward::End()
{
  drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoForward::Interrupted()
{
  drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}
