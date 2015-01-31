#ifndef InternalLift_H
#define InternalLift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class InternalLift: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon *left_lift, *right_lift;	// The motor controllers for the internal lift


public:
	InternalLift();
	void InitDefaultCommand();
};

#endif
