#ifndef InternalLift_H
#define InternalLift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class InternalLift: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon *left_lift_lead, *right_lift_lead;	    	// The motor controllers for the internal lift
	CANTalon *left_lift_follower, *right_lift_follower;	// the follower motor for each internal lift
	const float LIFT_SPEED = 0.5;
	const float CALI_SPEED = 0.1;
	const float REFRESH_LIMIT = 100000000000000;

	//TODO find encoder positions for tote and container
	const float TOTE_POSITION = 0.0;
	const float CONTAINER_POSITION = 0.0;

public:
	InternalLift();
	void InitDefaultCommand();

	void raise_lift();
	void lower_lift();
	void stop_lift();

	void calibrate();
	void update_status();

	void to_tote_position();
	void to_container_position();

	void move_lift(JoystickButton *x_button, JoystickButton *b_button);
};

#endif
