#ifndef AutoRotateRight_H
#define AutoRotateRight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoRotateRight: public CommandBase
{
public:
	AutoRotateRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
