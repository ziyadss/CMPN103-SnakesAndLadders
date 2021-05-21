#include "SwitchToPlayModeAction.h"
#include "SwitchToDesignModeAction.h"
#include "Grid.h"
#include "Player.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{

}
void SwitchToDesignModeAction::ReadActionParameters()
{
}

void SwitchToDesignModeAction::Execute()
{
	CardTen::pPlayerOwner = NULL;
	CardEleven::pPlayerOwner = NULL;
	CardTwelve::pPlayerOwner = NULL;
	CardThirteen::pPlayerOwner = NULL;
	CardFourteen::pPlayerOwner = NULL;

	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	inp->GetCellClicked();
	out->ClearStatusBar();
	out->CreateDesignModeToolBar();
	CellPosition StartCell(1);
	for (int i = 0; i < 4;i++)
	{
		Player* pl = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pl, StartCell);
		pl->turnCount = 0;
		pGrid->AdvanceCurrentPlayer();

	}




}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{

}
