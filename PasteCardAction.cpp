#include "PasteCardAction.h"
#include "Grid.h"
#include "Card.h"
#include "Cell.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	out->PrintMessage("Click on the destination cell");
	cardPosition = inp->GetCellClicked();
	if (!cardPosition.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cell, operation cancelled");
		return;
	}
	out->ClearStatusBar();
}
//check if cell has object
void PasteCardAction::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* pCard = pGrid->GetClipboard();
	if (!pCard)
		return;
	pCard->setPosition(cardPosition);
	pGrid->AddObjectToCell(pCard);


}

PasteCardAction::~PasteCardAction()
{

}