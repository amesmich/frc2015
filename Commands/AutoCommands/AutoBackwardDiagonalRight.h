#ifndef AutoBackwardDiagonalRight_H
#define AutoBackwardDiagonalRight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoBackwardDiagonalRight: public CommandBase
{
public:
	AutoBackwardDiagonalRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
