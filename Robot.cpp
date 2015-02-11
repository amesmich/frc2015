#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/MecanumDrive.h"
#include "Commands/AutoRun/AutoTest.h"
#include "Commands/AutoRun/AutoTest2.h"
#include "Commands/InternalLiftCommands/ManualInternalLift.h"
#include "Commands/InternalLiftCommands/ResetInternalLift.h"
#include "Commands/ExternalLiftCommands/MoveExternalLift.h"
#include "Commands/ExternalLiftCommands/ResetExternalLift.h"
#include "CommandBase.h"

/*
 * Author: Team 4638
 */

class Robot: public IterativeRobot
{
private:
	Command *auto_command, *mecanum_drive, *manual_external_lift,
			*manual_internal_lift;

	LiveWindow *lw;
	SendableChooser *chooser;
	InternalButton *internal_reset_button, *external_reset_button;

	void RobotInit()
	{
		CommandBase::init();
		// Set auto_command equal to example command if no command is to execute
		auto_command = new AutoTest ();			// The command to move forward and backward
		mecanum_drive = new MecanumDrive();		// The command to control to mecanum wheels
		manual_internal_lift = new ManualInternalLift();
		manual_external_lift = new MoveExternalLift();

		lw = LiveWindow::GetInstance();

		// This creates buttons on the smart dashboard
		// and then maps an option to each button
		chooser = new SendableChooser();
		chooser->AddDefault("Test 1 Auto Mode", new AutoTest());
		chooser->AddObject("Test 2 Auto mode", new AutoTest2());
		SmartDashboard::PutData("Auto Modes", chooser);

		// Button for resetting internal lift motors
		internal_reset_button = new InternalButton();
		SmartDashboard::PutData("Reset Internal", internal_reset_button);
		internal_reset_button->WhenPressed(new ResetInternalLift());

		// Button for resetting external lift motors
		external_reset_button = new InternalButton();
		SmartDashboard::PutData("Reset External", external_reset_button);
		external_reset_button->WhenPressed(new ResetExternalLift());
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (auto_command != NULL)
		{
			// waits to have an autonomous command selected
			auto_command = (Command *) chooser->GetSelected();
			auto_command->Start();

			CommandBase::drivetrain->update_status();		// Display the status of drivetrain motors
			CommandBase::internal_lift->update_status();	// Display the status of internal lift motors
		}
	}


	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();

		CommandBase::drivetrain->update_status();		// Display the status of drivetrain motors
		CommandBase::internal_lift->update_status();	// Display the status of internal lift motors
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (auto_command != NULL)
			auto_command->Cancel();

		mecanum_drive->Start();			// Start the drivetrain's commands
		manual_external_lift->Start();	// Start the external lift commands
		manual_internal_lift->Start();	// Start the internal lift commands

		CommandBase::drivetrain->update_status();		// Display the status of drivetrain motors
		CommandBase::internal_lift->update_status();	// Display the status of internal lift motors
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();

		CommandBase::drivetrain->update_status();		// Display the status of drivetrain motors
		CommandBase::internal_lift->update_status();	// Display the status of internal lift motors
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
