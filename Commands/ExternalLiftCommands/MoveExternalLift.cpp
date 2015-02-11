#include "MoveExternalLift.h"
#include "RobotMap.h"
#include "Subsystems/ExternalLift.h"

MoveExternalLift::MoveExternalLift()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (external_lift);
}

// Called just before this Command runs the first time
void MoveExternalLift::Initialize(){}

// Called repeatedly when this Command is scheduled to run
void MoveExternalLift::Execute()
{
	external_lift->move_lift(oi->joystick->GetRawAxis(LEFT_TRIGGER),
			                 oi->joystick->GetRawAxis(RIGHT_TRIGGER));
}

// Make this return true when this Command no longer needs to run execute()
bool MoveExternalLift::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveExternalLift::End()
{
	external_lift->move_lift(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveExternalLift::Interrupted()
{
	external_lift->move_lift(0.0, 0.0);
}
