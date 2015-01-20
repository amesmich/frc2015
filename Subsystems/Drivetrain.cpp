#include "Drivetrain.h"
#include "Commands/MecanumDrive.h"
#include "../RobotMap.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain")
{
	// Create the talon devices using can device id's as parameter
	front_left = new CANTalon(1);
	front_right = new CANTalon(2);
	back_left = new CANTalon(3);
	back_right = new CANTalon(4);

	drive = new RobotDrive(front_left, back_left, front_right, back_right);

	max_speed = 0.5;				// Set the default max speed to 0.5
}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand (new MecanumDrive());
}

/*
 * Function to provide mecanum drive controls for the motors
 *
 * x - the speed that the robot should drive in the X direction. [-1.0 .. 1.0]
 *
 * y - The speed that the robot should drive in the Y direction.
 * This input is inverted to match the forward == -1.0 that joysticks produce. [-1.0 .. 1.0]
 *
 * rotation - the rate of rotation for the robot that is
 * completely independent of the translation. [-1.0 .. 1.0]
 */

void Drivetrain::mecanum_drive(float x, float y, float rotation)
{
	// Have these in place in case of changes
	// but do not invert the direction of the left side wheels by default
	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
	drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);

	// Invert the right side wheels to allow for proper movement with mecanum wheels
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);

	// Assign a max speed for each of the motors
	// The max speed is set to 0.5 as default
	drive->SetMaxOutput(max_speed);

	// Provide the values needed to by the mecanum drive function
	drive->MecanumDrive_Cartesian(x, y, rotation);
}
