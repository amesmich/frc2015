#include "ResetInternalLift.h"
#include "Subsystems/InternalLift.h"

ResetInternalLift::ResetInternalLift()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires (internal_lift);
}

// Called just before this Command runs the first time
void ResetInternalLift::Initialize()
{
	internal_lift->calibrate();
}

// Called repeatedly when this Command is scheduled to run
void ResetInternalLift::Execute(){}

// Make this return true when this Command no longer needs to run execute()
bool ResetInternalLift::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetInternalLift::End(){}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetInternalLift::Interrupted(){}
