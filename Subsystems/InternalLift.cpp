#include "InternalLift.h"
#include "Commands/InternalLiftCommands/ManualInternalLift.h"
#include "../RobotMap.h"

/*
 * Author: Mehdi Moaddeb
 */

InternalLift::InternalLift() : Subsystem("InternalLift")
{
	// Initialize each device using the CAN device ID
	left_lift_lead = new CANTalon (11);
	left_lift_follower = new CANTalon (13);

	left_lift_follower->SetControlMode(CANSpeedController::kFollower);

	right_lift_lead = new CANTalon (12);
	right_lift_follower = new CANTalon (14);

	right_lift_follower->SetControlMode(CANSpeedController::kFollower);

	left_lift_lead->EnableControl();
	right_lift_lead->EnableControl();
	left_lift_follower->EnableControl();
	right_lift_follower->EnableControl();
}

void InternalLift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand(new ManualInternalLift());
}

/*
 * function to move both lifts up
 */

void InternalLift::raise_lift()
{
	left_lift_lead->Set(LIFT_SPEED);
	right_lift_lead->Set(LIFT_SPEED);
}

/*
 * function to lower both lifts
 */

void InternalLift::lower_lift()
{
	left_lift_lead->Set(-LIFT_SPEED);
	right_lift_lead->Set(-LIFT_SPEED);
}

/*
 * function to stop the lift
 */

void InternalLift::stop_lift()
{
	left_lift_lead->Set(0.0);
	right_lift_lead->Set(0.0);
}

/*
 * function to move the lift up or down based on the input from the
 * b & x buttons on the controller
 *
 * x_button - the x button on the controller
 * b_button - the b_button on the controller
 */

void InternalLift::move_lift(JoystickButton *x_button, JoystickButton *b_button)
{
	if (x_button->Get())
	{
		this->raise_lift();
	}
	else if (b_button->Get())
	{
		this->lower_lift();
	}
	else
	{
		this->stop_lift();
	}
}

/*
 * Function to take the lifts down and hit the limit switches
 * and re-raise them by half an inch to adjust the bottom limit
 * switches
 */

void InternalLift::calibrate()
{
	// refresh the bottom limit to allow for proper calibration
	left_lift_lead->ConfigReverseLimit(-REFRESH_LIMIT);
	right_lift_lead->ConfigReverseLimit(-REFRESH_LIMIT);

	left_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);
	right_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);

	left_lift_lead->EnableControl();
	right_lift_lead->EnableControl();

	// move the lift down until it hits the bottom limit switch
	while(left_lift_lead->GetReverseLimitOK())
	{
		left_lift_lead->Set(-CALI_SPEED);
	}

	while (right_lift_lead->GetReverseLimitOK())
	{
		right_lift_lead->Set(-CALI_SPEED);
	}

	// reset the encoder position to 0.0
	left_lift_lead->SetPosition(0.0);
	right_lift_lead->SetPosition(0.0);

	// TODO consider using ConfigLimitMode to turn
	// off limit switches

	// control the motors by counting the number of revolutions in a
	// specific direction
	left_lift_lead->SetControlMode(CANSpeedController::kPosition);
	left_lift_lead->EnableControl();

	right_lift_lead->SetControlMode(CANSpeedController::kPosition);
	right_lift_lead->EnableControl();

	// move the lift up by 4 rotations
	left_lift_lead->Set(4);
	right_lift_lead->Set(4);

	// reset the encoder value to 0.0
	left_lift_lead->SetPosition(0.0);
	right_lift_lead->SetPosition(0.0);

	// return the control mode of the controller to using percentVbus
	left_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);
	left_lift_lead->EnableControl();

	right_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);
	right_lift_lead->EnableControl();

	// Assign the new position as the soft limit for the bottom
	left_lift_lead->ConfigReverseLimit(left_lift_lead->GetEncPosition());
	right_lift_lead->ConfigReverseLimit(right_lift_lead->GetEncPosition());

	// Make the entire left side a follower of the right side motors
	left_lift_lead->SetControlMode(CANSpeedController::kFollower);
	left_lift_lead->Set(12);

	// set follower mode in motion
	right_lift_lead->EnableControl();
	left_lift_lead->EnableControl();
}

/*
 * The function will move the lift to the height
 * of one tote at the bottom of the robot
 */

void InternalLift::to_tote_position()
{
	// Set the lift motor control modes to position mode
	right_lift_lead->SetControlMode(CANSpeedController::kPosition);
	left_lift_lead->SetControlMode(CANSpeedController::kPosition);

	right_lift_lead->EnableControl();
	left_lift_lead->EnableControl();

	// move the lifts to the tote position
	right_lift_lead->Set(TOTE_POSITION);
	left_lift_lead->Set(TOTE_POSITION);

	// Put the the lift control mode back into the speed mode
	right_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);
	left_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);

	right_lift_lead->EnableControl();
	left_lift_lead->EnableControl();
}

/*
 * The function will move the lift to the of one
 * container at the bottom of the robot
 */

void InternalLift::to_container_position()
{
	// Set the lift motor control modes to position mode
	right_lift_lead->SetControlMode(CANSpeedController::kPosition);
	left_lift_lead->SetControlMode(CANSpeedController::kPosition);

	right_lift_lead->EnableControl();
	left_lift_lead->EnableControl();

	// move the lifts to the tote position
	right_lift_lead->Set(CONTAINER_POSITION);
	left_lift_lead->Set(CONTAINER_POSITION);

	// Put the the lift control mode back into the speed mode
	right_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);
	left_lift_lead->SetControlMode(CANSpeedController::kPercentVbus);

	right_lift_lead->EnableControl();
	left_lift_lead->EnableControl();
}

/*
 * Function to show the value of the encoders of the internal lift
 */

void InternalLift::update_status()
{
	SmartDashboard::PutNumber("Left lift voltage", left_lift_lead->GetOutputVoltage());
	SmartDashboard::PutNumber("Right lift voltage", right_lift_lead->GetOutputVoltage());

	SmartDashboard::PutNumber("Left lift current", left_lift_lead->GetOutputCurrent());
	SmartDashboard::PutNumber("Right lift current", right_lift_lead->GetOutputCurrent());
}
