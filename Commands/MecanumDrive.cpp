#include "Commands/MecanumDrive.h"
#include "Subsystems/Drivetrain.h"

MecanumDrive::MecanumDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires (drivetrain);
}

// Called just before this Command runs the first time
void MecanumDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MecanumDrive::Execute()
{
	// Get joystick axis values to drive using mecanum drive controls
	drivetrain->mecanum_drive(oi->joystick->GetRawAxis(0),	 // Left stick X-axis
						                oi->joystick->GetRawAxis(1),	 // Left stick Y-axis
						                oi->joystick->GetRawAxis(4));  // Right stick X-axis
	Wait (0.005);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDrive::IsFinished()
{
	// Command is only finished once the robot is disabled
	return false;
}

// Called once after isFinished returns true
void MecanumDrive::End()
{
	// Stop the motors once the command ends
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDrive::Interrupted()
{
	// Stop the motors if anything interrupts this command
	drivetrain->mecanum_drive(0.0, 0.0, 0.0);
}
