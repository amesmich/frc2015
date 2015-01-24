#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/MecanumDrive.h"
#include "Commands/AutoRun/AutoTest.h"
#include "Commands/AutoRun/AutoTest2.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	Command *auto_command, *mecanum_drive;
	LiveWindow *lw;
	SendableChooser *chooser;

	void RobotInit()
	{
		CommandBase::init();
		// Set auto_command equal to example command if no command is to execute
		auto_command = new AutoTest ();			// The command to move forward and backward
		mecanum_drive = new MecanumDrive();		// The command to control to mecanum wheels
		lw = LiveWindow::GetInstance();

		chooser = new SendableChooser();
		chooser->AddDefault("Test 1 Auto Mode", new AutoTest());
		chooser->AddObject("Test 2 Auto mode", new AutoTest2());
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (auto_command != NULL)
			auto_command->Start();
	}


	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
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
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}

	/*
	 * This function will call the SmartDashboard functions
	 * that are responsible for diagnostic informaiton
	 */

	void UpdateStaus()
	{
		CommandBase::drivetrain->update_status();
	}
};

START_ROBOT_CLASS(Robot);

