#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Ladder ladder(startPos, endPos);
	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	if (startPos.VCell() == -1 || startPos.HCell() == -1)
	{
		pOut->PrintMessage("Cancel operation; Please click on a valid Cell");
		return;
	}
	if (ladder.startCellLadder(startPos))
	{
		pOut->PrintMessage("Cancel operation; Ladder start cell cannot be in the last row");
		return;
	}
	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	if (endPos.VCell() == -1 || endPos.HCell() == -1)
	{
		pOut->PrintMessage("Cancel operation; Please click on a valid Cell");
		return;
	}

	///TODO: Make the needed validations on the read parameters
	
	if (ladder.AscendingLadder(startPos, endPos))
	{
		pOut->PrintMessage("End cell cannot be smaller than start cell");
		return;
	}
	if (ladder.VerticalLadder(startPos,endPos))
	{
		pOut->PrintMessage("End cell and start cell are not in the same column");
		return;
	}


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (startPos.VCell() == -1 || startPos.HCell() == -1 || endPos.VCell() == -1 || endPos.HCell() == -1)
	{
		return;
	}

	// Create a Ladder object with the parameters read from the user
	Ladder* pLadder = new Ladder(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	if (pGrid->IsOverlapping(pLadder))
		return;
	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
