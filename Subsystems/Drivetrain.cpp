#include "Drivetrain.h"
#include "Commands/MecanumDrive.h"
#include "../RobotMap.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain")
{
	// Create the talon devices using can device id's as parameter
	front_left = new CANTalon(FRONT_LEFT_MOTOR);
	front_right = new CANTalon(FRONT_RIGHT_MOTOR);
	back_left = new CANTalon(BACK_LEFT_MOTOR);
	back_right = new CANTalon(BACK_RIGHT_MOTOR);

	drive = new RobotDrive(front_left, back_left, front_right, back_right);
	drive->SetSafetyEnabled(false);	// Disable motor safety to avoid crashes

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
	// If the robot is in default drive mode use this driver perspective
	// Otherwise switch the front of the robot to the other side
	if(this->is_default_mode)
	{
		// do not invert the direction of the left side wheels by default
		drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
		drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);

		// Invert the right side wheels to allow for proper movement with mecanum wheels
		drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	}
	else
	{
		// invert the direction of the left side wheels
		drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

		// Return the inverted motors to their default
		drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
		drive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);
	}

	// Assign a max speed for each of the motors
	// The max speed is set to 0.5 as default
	drive->SetMaxOutput(MAX_SPEED);

	// Provide the values needed to by the mecanum drive function
	drive->MecanumDrive_Cartesian(x, y, rotation);
}


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
	// Gets the temperature of all of the motors
	SmartDashboard::PutNumber("Temperature of the Front Left Motor", front_left->GetTemperature());
	SmartDashboard::PutNumber("Temperature of the Front Right Motor", front_right->GetTemperature());
	SmartDashboard::PutNumber("Temperature of the Back Left Motor", back_left->GetTemperature());
	SmartDashboard::PutNumber("Temperature of the Back Right Motor", back_right->GetTemperature());

	// Gets the voltage of all the motors
	SmartDashboard::PutNumber("Voltage of the Front Left Motor", front_left->GetOutputVoltage());
	SmartDashboard::PutNumber("Voltage of the Front Right Motor", front_right->GetOutputVoltage());
	SmartDashboard::PutNumber("Voltage of the Back Left Motor", back_left->GetOutputVoltage());
	SmartDashboard::PutNumber("Voltage of the Back Right Motor", back_right->GetOutputVoltage());
}

