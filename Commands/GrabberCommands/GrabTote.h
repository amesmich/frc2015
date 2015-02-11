#ifndef GrabTote_H
#define GrabTote_H

#include "../../CommandBase.h"
#include "WPILib.h"

class GrabTote: public CommandBase
{
public:
	GrabTote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
