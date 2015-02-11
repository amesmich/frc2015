#ifndef AutoBackwardDiagonalLeft_H
#define AutoBackwardDiagonalLeft_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoBackwardDiagonalLeft: public CommandBase
{
public:
	AutoBackwardDiagonalLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
