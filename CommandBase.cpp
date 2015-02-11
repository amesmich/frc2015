#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/InternalLift.h"
#include "Subsystems/ActiveGrabber.h"
#include "Subsystems/ExternalLift.h"
#include "Commands/Scheduler.h"
#include "WPILib.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
Drivetrain* CommandBase::drivetrain = NULL;
InternalLift* CommandBase::internal_lift = NULL;
ExternalLift* CommandBase::external_lift = NULL;
ActiveGrabber* CommandBase::active_grabber = NULL;
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
	SmartDashboard::init();

	examplesubsystem = new ExampleSubsystem();
	drivetrain = new Drivetrain ();
	internal_lift = new InternalLift ();
	external_lift = new ExternalLift();
	active_grabber = new ActiveGrabber();
	oi = new OI();
}
