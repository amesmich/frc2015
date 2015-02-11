#include "AutoBackwardDiagonalLeft.h"
#include "RobotMap.h"

AutoBackwardDiagonalLeft::AutoBackwardDiagonalLeft()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (drivetrain);
}

// Called just before this Command runs the first time
void AutoBackwardDiagonalLeft::Initialize(){}

// Called repeatedly when this Command is scheduled to run
void AutoBackwardDiagonalLeft::Execute()
{
	drivetrain->mecanum_drive(-SLOW_SPEED, SLOW_SPEED, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoBackwardDiagonalLeft::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoBackwardDiagonalLeft::End()
{
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBackwardDiagonalLeft::Interrupted()
{
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}
