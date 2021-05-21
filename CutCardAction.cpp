#include "CutCardAction.h"
#include "Grid.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	out->PrintMessage("Click on the source cell");
	cardPosition = inp->GetCellClicked();
	if (!cardPosition.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cell, operation cancelled");
		return;
	}
	out->ClearStatusBar();
}

void CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (!(pGrid->GetCard(cardPosition)))
		return;
	pGrid->SetClipboard(pGrid->GetCard(cardPosition));
	pGrid->RemoveObjectFromCell(cardPosition);
}

CutCardAction::~CutCardAction()
{

}
