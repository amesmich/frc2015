#ifndef MoveExternalLift_H
#define MoveExternalLift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class MoveExternalLift: public CommandBase
{
public:
	MoveExternalLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
