#ifndef AutoForwardDiagonalLeft_H
#define AutoForwardDiagonalLeft_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoForwardDiagonalLeft: public CommandBase
{
public:
	AutoForwardDiagonalLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
