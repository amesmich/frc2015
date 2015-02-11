#include "ResetExternalLift.h"
#include "Subsystems/ExternalLift.h"

ResetExternalLift::ResetExternalLift()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (external_lift);
}

// Called just before this Command runs the first time
void ResetExternalLift::Initialize()
{
	external_lift->calibrate();
}

// Called repeatedly when this Command is scheduled to run
void ResetExternalLift::Execute(){}

// Make this return true when this Command no longer needs to run execute()
bool ResetExternalLift::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetExternalLift::End()
{
	external_lift->stop_lift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetExternalLift::Interrupted()
{
	external_lift->stop_lift();
}
