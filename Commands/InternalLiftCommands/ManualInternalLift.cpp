#include "ManualInternalLift.h"
#include "Subsystems/InternalLift.h"

ManualInternalLift::ManualInternalLift()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (internal_lift);
}

// Called just before this Command runs the first time
void ManualInternalLift::Initialize(){}

// Called repeatedly when this Command is scheduled to run
void ManualInternalLift::Execute()
{
	internal_lift->move_lift(oi->x_button, oi->b_button);
}

// Make this return true when this Command no longer needs to run execute()
bool ManualInternalLift::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ManualInternalLift::End()
{
	internal_lift->stop_lift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualInternalLift::Interrupted()
{
	internal_lift->stop_lift();
}
