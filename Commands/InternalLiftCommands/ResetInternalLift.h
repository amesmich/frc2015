#ifndef ResetInternalLift_H
#define ResetInternalLift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ResetInternalLift: public CommandBase
{
public:
	ResetInternalLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
