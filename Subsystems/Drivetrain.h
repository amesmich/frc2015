#ifndef Drivetrain_H
#define Drivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivetrain: public Subsystem
{
private:
	CANTalon *rightBackMotor, *leftBackMotor,
	        *rightFrontMotor, *leftFrontMotor;
	RobotDrive *drive;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Drivetrain();
	void InitDefaultCommand();
	void tankDrive(Joystick*, Joystick*);
	void tankDrive(float, float);

};

#endif
