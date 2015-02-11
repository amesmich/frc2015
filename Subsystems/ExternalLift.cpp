#include "ExternalLift.h"
#include "Commands/ExternalLiftCommands/MoveExternalLift.h"
#include "../RobotMap.h"

ExternalLift::ExternalLift(): Subsystem("External Lift")
{
	back_lift_lead = new CANTalon (17);
	back_lift_follower = new CANTalon (18);

	back_lift_follower->SetControlMode(CANSpeedController::kFollower);
	back_lift_follower->Set(17);

	back_lift_lead->EnableControl();
	back_lift_follower->EnableControl();
}

void ExternalLift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand (new MoveExternalLift());
}

/*
 * Function that makes the external lift move upwards
 */

void ExternalLift::raise_lift()
{
	back_lift_lead->Set(LIFT_SPEED);
}

/*
 * Function that makes the external lift move downwards
 */

void ExternalLift::lower_lift()
{
	back_lift_lead->Set(-LIFT_SPEED);
}

/*
 * Function that makes the external lift stop
 */

void ExternalLift::stop_lift()
{
	back_lift_lead->Set(0.0);
}

/*
 * A function that determines which trigger is being pressed on the controller
 * and moves the external grabber accordingly based on input
 *
 * left_trigger - the value from the left trigger on the controller
 * right_trigger - the value from the right trigger on the controller
 */

void ExternalLift::move_lift(float left_trigger, float right_trigger)
{
	if ((left_trigger > 0) && (right_trigger == 0))
	{
		this->raise_lift();
	}
	else if ((left_trigger == 0) && (right_trigger > 0))
	{
		this->lower_lift();
	}
	else
	{
		this->stop_lift();
	}
}

/*
 * A function that makes the external grabber go to the bottom and
 * adjusts the bottom limit
 */

void ExternalLift::calibrate()
{
	// refresh the bottom limit to allow for proper calibration
	back_lift_lead->ConfigReverseLimit(-REFRESH_LIMIT);

	// move the lift down until it hits the bottom limit switch
	while(back_lift_lead->GetReverseLimitOK())
	{
		back_lift_lead->Set(-CALI_SPEED);
	}

	// reset the encoder position to 0.0
	back_lift_lead->SetPosition(0.0);

	// TODO consider using ConfigLimitMode to turn
	// off limit switches

	// control the motors by counting the number of revolutions in a
	// specific direction
	back_lift_lead->SetControlMode(CANSpeedController::kPosition);
	back_lift_lead->EnableControl();

	// move the lift up by 4 rotations
	back_lift_lead->Set(4);
	// reset the encoder value to 0.0
	back_lift_lead->SetPosition(0.0);

	// return the control mode of the controller to using percentVbus
	back_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);
	back_lift_lead->EnableControl();

	// Assign the new position as the soft limit for the bottom
	back_lift_lead->ConfigReverseLimit(back_lift_lead->GetEncPosition());
}

/*
 * Shows the position of the encoder, the output current, and
 * the output voltage for the external grabber
 */

void ExternalLift::update_status()
{
	SmartDashboard::PutNumber("External lift position", back_lift_lead->GetEncPosition());
	SmartDashboard::PutNumber("External lift current", back_lift_lead->GetOutputCurrent());
	SmartDashboard::PutNumber("External lift voltage", back_lift_lead->GetOutputVoltage());
}
