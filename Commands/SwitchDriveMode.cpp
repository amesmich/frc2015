#include "SwitchDriveMode.h"
#include "Subsystems/Drivetrain.h"

SwitchDriveMode::SwitchDriveMode()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (drivetrain);

	timer = new Timer();
}

// Called just before this Command runs the first time
void SwitchDriveMode::Initialize()
{
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void SwitchDriveMode::Execute()
{
	// Switch the driver's perspective when this command is called
	drivetrain->switch_drive_mode();

	// Wait to ensure proper execution of the command
	Wait (0.005);
}

// Make this return true when this Command no longer needs to run execute()
bool SwitchDriveMode::IsFinished()
{
	// End once the timer has exceeded the wait period
	return timer->Get() > 0.005;
}

// Called once after isFinished returns true
void SwitchDriveMode::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchDriveMode::Interrupted()
{
	timer->Stop();
}
