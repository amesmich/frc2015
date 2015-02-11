#ifndef ManualInternalLift_H
#define ManualInternalLift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ManualInternalLift: public CommandBase
{
public:
	ManualInternalLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
