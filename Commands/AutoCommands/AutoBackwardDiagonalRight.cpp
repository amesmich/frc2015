#include "AutoBackwardDiagonalRight.h"
#include "RobotMap.h"

AutoBackwardDiagonalRight::AutoBackwardDiagonalRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (drivetrain);
}

// Called just before this Command runs the first time
void AutoBackwardDiagonalRight::Initialize(){}

// Called repeatedly when this Command is scheduled to run
void AutoBackwardDiagonalRight::Execute()
{
	drivetrain->mecanum_drive(SLOW_SPEED, SLOW_SPEED, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoBackwardDiagonalRight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoBackwardDiagonalRight::End()
{
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBackwardDiagonalRight::Interrupted()
{
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}
