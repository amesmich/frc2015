#include "ActiveGrabber.h"
#include "../RobotMap.h"


ActiveGrabber::ActiveGrabber() : Subsystem("ExampleSubsystem")
{
  //Create the talon controllers with the device IDs
  left_grabber = new CANTalon(LEFT_GRABBER_MOTOR);
  right_grabber = new CANTalon(RIGHT_GRABBER_MOTOR);
  right_grabber->SetSensorDirection(true);  //TODO find which motor ought to be reversed
}

void ActiveGrabber::InitDefaultCommand()
{

}

void ActiveGrabber::spin_motors_in()
{
  left_grabber->Set(MAX_SPEED * GRAB_SPEED);
  right_grabber->Set(MAX_SPEED * GRAB_SPEED);
}

void ActiveGrabber::spin_motors_out()
{
  left_grabber->Set(MAX_SPEED * -GRAB_SPEED);
  right_grabber->Set(MAX_SPEED * -GRAB_SPEED);
}

void ActiveGrabber::stall_motors()
{
  left_grabber->Set(MAX_SPEED * STALL_SPEED);
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
