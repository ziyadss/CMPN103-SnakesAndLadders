#include "SwitchToPlayModeAction.h"
#include "SwitchToDesignModeAction.h"
#include "Grid.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{

}
void SwitchToPlayModeAction::ReadActionParameters()
{
}

void SwitchToPlayModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();

	
		out->CreatePlayModeToolBar();




}

SwitchToPlayModeAction::~SwitchToPlayModeAction()
{

}
