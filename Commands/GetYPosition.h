#ifndef GetYPosition_H
#define GetYPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class GetYPosition: public CommandBase
{
public:
	GetYPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
