#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/InternalLift.h"
#include "Subsystems/ExternalLift.h"
#include "Subsystems/ActiveGrabber.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static ExampleSubsystem *examplesubsystem;
	static Drivetrain *drivetrain;
	static InternalLift *internal_lift;
	static ExternalLift *external_lift;
	static ActiveGrabber *active_grabber;
	static OI *oi;
};

#endif
