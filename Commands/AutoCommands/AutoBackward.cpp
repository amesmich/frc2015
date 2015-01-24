#include "AutoBackward.h"

/*
 * Auto test command to move backwards
 */

AutoBackward::AutoBackward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (drivetrain);
}

// Called just before this Command runs the first time
void AutoBackward::Initialize(){}

// Called repeatedly when this Command is scheduled to run
void AutoBackward::Execute()
{
	drivetrain->mecanum_drive(0.0, -0.25, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoBackward::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoBackward::End()
{
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBackward::Interrupted()
{
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}
