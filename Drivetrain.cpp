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
	drive->SetSafetyEnabled(false);	// Disable motor safety helper to avoid crashes

	max_speed = 0.5;				// Set the default max speed to 0.5
	is_default_mode = true;			// By default the driver's perspective should be in the front
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
	// Assign a max speed for each of the motors
	// The max speed is set to 0.5 as default
	drive->SetMaxOutput(max_speed);

	// If the robot is in default drive mode use this driver perspective,
	// otherwise switch the front of the robot to the other side.
	// The driver perspective is switched by pressing 'A' on the controller
	if(this->is_default_mode)
	{
		// do not invert the direction of the left side wheels by default
		drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
		drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);

		// Invert the right side wheels to allow for proper movement with mecanum wheels
		drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);

		// Provide the values needed to by the mecanum drive function
		drive->MecanumDrive_Cartesian(x, y, rotation);
	}
	else
	{
		// invert the direction of the left side wheels
		drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

		// Return the inverted motors to their default
		drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
		drive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);

		// Provide the values needed to by the mecanum drive function
		// invert the rotation to adjust for the change in perspective
		drive->MecanumDrive_Cartesian(x, y, -1 * rotation);
	}
}

/*
 * Switch the drive mode of the robot to the opposite
 * of its current drive state. This function will be
 * used when the 'A' button on the controller is pressed
 */

void Drivetrain::switch_drive_mode()
{
	is_default_mode = !is_default_mode;
}

/*
 * set the drive mode to the original orientation
 * when the robot first starts
 */

void Drivetrain::set_drive_mode_default()
{
	is_default_mode = true;
}

// ACCESSOR

/*
 * returns the current drive mode that the
 * robot is in
 */

bool Drivetrain::get_drive_mode()
{
	return is_default_mode;
}

/*
 * This function will utilize the smart dashboard to display
 * the status of each motor's temperature and voltage
 */

void Drivetrain::update_status()
{
	// Show the current drive mode of the robot
	// If it is in default mode display default,
	// otherwise display alternate as the mode.
	if (this->get_drive_mode())
	{
		SmartDashboard::PutString("Drive mode", "Default");
	}
	else
	{
		SmartDashboard::PutString("Drive mode", "Alternate");
	}

	// Gets the temperature of all of the motors and displays them on the smart dashboard
	SmartDashboard::PutNumber("Temperature of the Front Left Motor", front_left->GetTemperature());
	SmartDashboard::PutNumber("Temperature of the Front Right Motor", front_right->GetTemperature());
	SmartDashboard::PutNumber("Temperature of the Back Left Motor", back_left->GetTemperature());
	SmartDashboard::PutNumber("Temperature of the Back Right Motor", back_right->GetTemperature());

	// Gets the voltage of all the motors and displays them on the smart dashboard
	SmartDashboard::PutNumber("Voltage of the Front Left Motor", front_left->GetOutputVoltage());
	SmartDashboard::PutNumber("Voltage of the Front Right Motor", front_right->GetOutputVoltage());
	SmartDashboard::PutNumber("Voltage of the Back Left Motor", back_left->GetOutputVoltage());
	SmartDashboard::PutNumber("Voltage of the Back Right Motor", back_right->GetOutputVoltage());
}

