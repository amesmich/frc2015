#ifndef AutoForwardDiagonalRight_H
#define AutoForwardDiagonalRight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoForwardDiagonalRight: public CommandBase
{
public:
	AutoForwardDiagonalRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
