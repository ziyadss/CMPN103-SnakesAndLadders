#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardTwo.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp) {
}
EditCardAction::~EditCardAction()
{
}
void EditCardAction::ReadActionParameters() {

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();

	// 2- Read the pointer parameter and set its data member
	out->PrintMessage("click on cell to edit");
	CellPosition pos = inp->GetCellClicked();
	editcard = pGrid->GetCard(pos);
	if (editcard == NULL) {
		out->PrintMessage("No card");
	}
	cardnum = editcard->GetCardNumber();
	
}
void EditCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	if (editcard == NULL && cardnum != 1 && cardnum != 2 && cardnum != 9 && cardnum != 10 && cardnum != 11 && cardnum != 12 && cardnum != 13 && cardnum != 14) {
		out->PrintMessage("card can't be edited");
		return;
	}
	else {
		editcard->EditCard(pGrid);
	}
}