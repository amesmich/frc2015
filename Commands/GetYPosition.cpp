#include "GetYPosition.h"
#include "../Subsystems/Drivetrain.h";

GetYPosition::GetYPosition()
{
	Requires(Drivetrain);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void GetYPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GetYPosition::Execute()
{
	drivetrain->leftBackMotor(oi->leftJoystick->GetY());
	drivetrain->rightBackMotor(oi->rightJoystick->GetY());
	drivetrain->leftFrontMotor(oi->leftJoystick->GetY());
	drivetrain->rightFrontMotor(oi->rightJoystick->GetY());

}

// Make this return true when this Command no longer needs to run execute()
bool GetYPosition::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GetYPosition::End()
{
	drivetrain->leftBackMotor->Set(0.0);
	drivetrain->rightBackMotor->Set(0.0);
	drivetrain->leftFrontMotor->Set(0.0);
	drivetrain->rightFrontMotor->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetYPosition::Interrupted()
{

}
