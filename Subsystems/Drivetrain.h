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
	Gyro *gyro;

	float max_speed;			// The maximum speed the motors can be at
	bool is_default_mode;		// boolean to check the driving perspective

public:
	Drivetrain();
	void InitDefaultCommand();
	void mecanum_drive(float x, float y, float rotation);

	void switch_drive_mode();
	void set_drive_mode_default();
	bool get_drive_mode();

	void inti_gyro();
	void header();

	void update_status();
};

#endif
