#ifndef Drivetrain_H
#define Drivetrain_H

#include "Commands/Subsystem.h"
#include "RobotMap.h"
#include "WPILib.h"

class Drivetrain: public Subsystem
{
private:

	// The four motor controllers for the robot
	CANTalon *front_left, *front_right,
			 *back_left, *back_right;

	RobotDrive *drive;			// Create a RobotDrive to use its mecanum drive features

	bool is_default_mode;		// boolean to check the driving perspective

public:
	Drivetrain();
	void InitDefaultCommand();
	void mecanum_drive(float x, float y, float rotation);

	void switch_drive_mode();
	void set_drive_mode_default();

	bool get_drive_mode();

	void update_status();
};

#endif
