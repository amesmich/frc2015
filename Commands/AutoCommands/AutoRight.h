#ifndef AutoRight_H
#define AutoRight_H

#include "CommandBase.h"
#include "RobotMap.h"
#include "WPILib.h"

class AutoRight: public CommandBase
{
public:
	AutoRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
