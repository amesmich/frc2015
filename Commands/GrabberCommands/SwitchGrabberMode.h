#ifndef SwitchGrabberMode_H
#define SwitchGrabberMode_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SwitchGrabberMode: public CommandBase
{
public:
	SwitchGrabberMode();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
