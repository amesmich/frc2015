#ifndef SwitchDriveMode_H
#define SwitchDriveMode_H

#include "../CommandBase.h"
#include "WPILib.h"

class SwitchDriveMode: public CommandBase
{
private:
	Timer *timer;

public:
	SwitchDriveMode();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
