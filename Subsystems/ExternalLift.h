#ifndef ExternalLift_H
#define ExternalLift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExternalLift: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon *back_lift_lead;		// The back lift motor controllers
	CANTalon *back_lift_follower;	// this one will be a follower of back_lift_lead

	const float LIFT_SPEED = 0.5;
	const float CALI_SPEED = 0.1;
	const float REFRESH_LIMIT = 100000000000000;

public:
	ExternalLift();
	void InitDefaultCommand();

	void move_lift(float left_trigger, float right_trigger);
	void raise_lift();
	void lower_lift();
	void stop_lift();

	void calibrate ();
	void update_status();
};

#endif
