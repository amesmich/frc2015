#ifndef ActiveGrabber_H
#define ActiveGrabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class ActiveGrabber: public Subsystem
{
private:

  //The Two motor controllers for the ActiveGrabber
  CANTalon *left_grabber, *right_grabber;

public:
	ActiveGrabber();
	void InitDefaultCommand();
	void spin_motors_in();
	void spin_motors_out();
	void stall_motors();
	bool is_left_motor_stalled();
	bool is_right_motor_stalled();
	void update_status();
};

#endif
