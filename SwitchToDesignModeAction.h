#pragma once
#include "Action.h"
class SwitchToDesignModeAction :
	public Action
{
	int mode;

public:

	SwitchToDesignModeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwitchToDesignModeAction();
};

