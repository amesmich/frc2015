#ifndef Drivetrain_H
#define Drivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivetrain: public Subsystem
{
private:

	// The four motor controllers for the robot
	CANTalon *front_left, *front_right,
			 *back_left, *back_right;

	RobotDrive *drive;			// Create a RobotDrive to use its mecanum drive features

	float max_speed;			// The maximum speed the motors can be at

public:
	Drivetrain();
	void InitDefaultCommand();
	void mecanum_drive(float x, float y, float rotation);
};

#endif
