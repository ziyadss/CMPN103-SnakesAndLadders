#pragma once
#include "Action.h"
class PasteCardAction :
	public Action
{
	CellPosition cardPosition;

public:

	PasteCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~PasteCardAction();
};

