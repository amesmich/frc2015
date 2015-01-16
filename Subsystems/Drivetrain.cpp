#include "Drivetrain.h"
#include "../RobotMap.h"
#include "WPILib.h"

Drivetrain::Drivetrain() : Subsystem("ExampleSubsystem")
{
  leftBackMotor = new CANTalon(3), rightBackMotor = new CANTalon(4),
    leftFrontMotor = new CANTalon(1), rightFrontMotor = new CANTalon(2);

	drive = new RobotDrive;
}

void Drivetrain::InitDefaultCommand()
{
	SetDefaultCommand(new GetYPosition);
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Drivetrain::tankDrive(Joystick *leftJoystick, Joystick *rightJoystick)
{
	drive->TankDrive(leftJoystick, rightJoystick);
}

void Drivetrain::tankDrive(float leftSpeed, float rightSpeed)
{
	drive->TankDrive(leftSpeed, rightSpeed);
}


void Drivetrain::rightBackMotor(float speed)
{
	rightBackMotor->Set(speed);
}

void Drivetrain::leftBackMotor(float speed)
{
	leftBackMotor->Set(speed);
}

void Drivetrain::rightFrontMotor(float speed)
{
  rightFrontMotor->Set(speed);
}

void Drivetrain::leftFrontMotor(float speed)
{
  leftFrontMotor->Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
