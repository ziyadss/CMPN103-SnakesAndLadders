#pragma once
#include "Action.h"
#include "Grid.h"
#include <fstream>
class SaveGridAction :
	public Action
{
	string fname;
public:
	SaveGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SaveGridAction();
};

