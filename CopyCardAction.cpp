#include "CopyCardAction.h"
#include "Grid.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CopyCardAction::ReadActionParameters()
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

void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (!(pGrid->GetCard(cardPosition)))
		return;
	pGrid->SetClipboard(pGrid->GetCard(cardPosition));
}

CopyCardAction::~CopyCardAction()
{

}
