#include "AutoRotateRight.h"
#include "RobotMap.h"

AutoRotateRight::AutoRotateRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (drivetrain);
}

// Called just before this Command runs the first time
void AutoRotateRight::Initialize(){}

// Called repeatedly when this Command is scheduled to run
void AutoRotateRight::Execute()
{
	drivetrain->mecanum_drive(0.0, 0.0, SLOW_SPEED);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRotateRight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoRotateRight::End()
{
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRotateRight::Interrupted()
{
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}
