#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Drivetrain.h"
#include "Commands/Scheduler.h"
#include "WPILib.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
Drivetrain* CommandBase::drivetrain = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	drivetrain = new Drivetrain ();
	oi = new OI();
	active_grabber = new ActiveGrabber();

	SmartDashboard::init();
	SmartDashboard::PutBoolean("Default drive mode", drivetrain->get_drive_mode());
}
