#ifndef ResetExternalLift_H
#define ResetExternalLift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ResetExternalLift: public CommandBase
{
public:
	ResetExternalLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
