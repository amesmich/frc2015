#include "InternalLift.h"
#include "../RobotMap.h"

InternalLift::InternalLift() : Subsystem("Internal Lift")
{
	// Initialize each device using the CAN device ID
	left_lift = new CANTalon (21);
	right_lift = new CANTalon (22);
}

void InternalLift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
