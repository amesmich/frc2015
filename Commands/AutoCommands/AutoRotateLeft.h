#ifndef AutoRotateLeft_H
#define AutoRotateLeft_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoRotateLeft: public CommandBase
{
public:
	AutoRotateLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
