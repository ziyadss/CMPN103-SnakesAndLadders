#include "NewGameAction.h"
#include "Grid.h"
#include "Cell.h"
#include "Player.h"
#include "DeleteGameObject.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{

}
void NewGameAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	inp->GetCellClicked();
	out->ClearStatusBar();

}

void NewGameAction::Execute()
{
	CardTen::pPlayerOwner = NULL;
	CardEleven::pPlayerOwner = NULL;
	CardTwelve::pPlayerOwner = NULL;
	CardThirteen::pPlayerOwner = NULL;
	CardFourteen::pPlayerOwner = NULL;
	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	CellPosition StartCell(1);
	for (int i = 0; i < 4;i++)
	{
		Player* pl = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pl, StartCell);
		pl->turnCount = 0;
		pGrid->AdvanceCurrentPlayer();

	}





}

NewGameAction::~NewGameAction()
{

}


