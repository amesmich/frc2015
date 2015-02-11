#ifndef ActiveGrabber_H
#define ActiveGrabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ActiveGrabber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon *left_grabber, *right_grabber;
	bool is_default_mode;
public:
	ActiveGrabber();
	void InitDefaultCommand();
	void active_grabber();
	void spin_motors_in();
	void spin_motors_out();
	void stall_motors();
	bool is_left_motor_stalled();
	bool is_right_motor_stalled();
	void update_status();
	void switch_grabber_mode();
	void set_grabber_mode_default();
	bool get_grabber_mode();

};

#endif
