#include "TankDrive.h"
#include "../Subsystems/Drivetrain.h";

TankDrive::TankDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void TankDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute()
{
	drivetrain->tankDrive(oi->leftJoystick, oi->rightJoystick);
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TankDrive::End()
{
	drivetrain->tankDrive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted()
{
	drivetrain->tankDrive(0.0, 0.0);
}
