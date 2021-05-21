#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Snake snake(startPos,endPos);
	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	if (startPos.VCell() == -1 || startPos.HCell() == -1)
	{
		pOut->PrintMessage("Cancel operation; Please click on a valid Cell");
		return;
	}
	if (snake.startCellSnake(startPos))
	{
		pOut->PrintMessage("Cancel operation; Snake start cell cannot be in the First row");
		return;
	}
	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	if (endPos.VCell() == -1 || endPos.HCell() == -1)
	{
		pOut->PrintMessage("Cancel operation; Please click on a valid Cell");
		return;
	}

	///TODO: Make the needed validations on the read parameters

	if (snake.DescendingSnake(startPos,endPos))
	{
		pOut->PrintMessage("stert cell cannot be smaller than end cell");
		return;
	}
	if (snake.VerticalSnake(startPos,endPos))
	{
		pOut->PrintMessage("End cell and start cell are not in the same column");
		return;
	}
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (startPos.VCell()==-1 || startPos.HCell()==-1 || endPos.VCell()==-1 || endPos.HCell()==-1)
	{
		return;
	}
	else
	{
		// Create a Snake object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);

		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
		if (pGrid->IsOverlapping(pSnake))
			return;
		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
	}
}
