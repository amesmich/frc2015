#ifndef AutoLeft_H
#define AutoLeft_H

#include "CommandBase.h"
#include "RobotMap.h"
#include "WPILib.h"

class AutoLeft: public CommandBase
{
public:
	AutoLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
