#include "ActiveGrabber.h"
#include "RobotMap.h"


ActiveGrabber::ActiveGrabber() : Subsystem("ExampleSubsystem")
{
  //Create the talon controllers with the device IDs
  left_grabber = new CANTalon(LEFT_GRABBER_MOTOR);
  right_grabber = new CANTalon(RIGHT_GRABBER_MOTOR);
  left_grabber->SetControlMode(CANSpeedController::kFollower);
  left_grabber->Set(RIGHT_GRABBER_MOTOR);
  left_grabber->SetSensorDirection(true);

}

//Right motor: CW to move outwards, CCW to move inwards of the robot
//Left motor: CCW to move outwards, CW to move inwards of the robot
//CW is a + value, CCW is a - value

void ActiveGrabber::InitDefaultCommand()
{

}

void ActiveGrabber::spin_motors_in()
{
  right_grabber->Set(MAX_SPEED * GRAB_SPEED);
}

void ActiveGrabber::spin_motors_out()
{
  right_grabber->Set(MAX_SPEED * -GRAB_SPEED);
}

void ActiveGrabber::stall_motors()
{
  right_grabber->Set(MAX_SPEED * STALL_SPEED);
}

bool ActiveGrabber::is_left_motor_stalled()
{
  if (left_grabber->GetOutputCurrent() > 1.5)
  {
      return true;
  }
  return false;
}

bool ActiveGrabber::is_right_motor_stalled()
{
  if (right_grabber->GetOutputCurrent() > 1.5)
  {
    return true;
  }
  return false;
}

void ActiveGrabber::update_status()
{

  //To ensure that these motors don't explode :)))
  SmartDashboard::PutNumber("Temperature of the Right Grabber Motor ", right_grabber->GetTemperature());
  SmartDashboard::PutNumber("Temperature of the Left Grabber Motor  ", left_grabber->GetTemperature());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
