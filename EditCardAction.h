#pragma once
#include "Action.h"
class EditCardAction :
	public Action
{
	Card* editcard;
	int cardnum;
	// [Action Parameters]
	Cell* pCell;

	// Note: These parameters should be read in ReadActionParameters()

public:
	EditCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute();

	virtual ~EditCardAction(); // A Virtual Destructor

};

