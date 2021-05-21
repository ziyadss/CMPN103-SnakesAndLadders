#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"
InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}
void InputDiceValueAction::ReadActionParameters()
{
	Input* pIn = pManager->GetGrid()->GetInput();
	Output* pO = pManager->GetGrid()->GetOutput();
	pO->PrintMessage("Enter dice value (1-6): ");
	diceNumber = pIn->GetInteger(pO);
	pO->ClearStatusBar();
}
void InputDiceValueAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (diceNumber < 1 || diceNumber>6)
	{
		pGrid->PrintErrorMessage("Invalid dice number, operation cancelled");
		return;
	}
	if (pGrid->GetEndGame())
		return;
	Player* pPlayer = pGrid->GetCurrentPlayer();
	pPlayer->Move(pGrid, diceNumber);
	pGrid->AdvanceCurrentPlayer();
}
InputDiceValueAction::~InputDiceValueAction()
{

}