#pragma once
#include "Action.h"
class CutCardAction :
	public Action
{
	CellPosition cardPosition;

public:

	CutCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CutCardAction();
};

