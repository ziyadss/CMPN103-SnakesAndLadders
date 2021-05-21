#include "CardFive.h"


CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	Player* pPlayer;


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();

	// 2- print to a descriptive message to the user like:"New CardFive: Moves farward the same number or steps you just rolled"
	pOut->PrintMessage("New CardFive: Moves forward the same number or steps you just rolled");

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Move the player forward the same number of steps that they just rolled
	int JustRolledDiceNumber = pPlayer->GetjustRolledDiceNum();
	int cellnumber = position.GetCellNumFromPosition(position);
	int newCellNumber = cellnumber + JustRolledDiceNumber;
	CellPosition pos = position.GetCellPositionFromNum(newCellNumber);
	pGrid->UpdatePlayerCell(pPlayer, pos);
	Cell* cell = pPlayer->GetCell();
	GameObject* gO = cell->GetGameObject();
	if (gO) {
		gO->Apply(pGrid, pPlayer);
	}
}
void CardFive::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardFive::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum;
	InFile >> cellNum;

	position = CellPosition::GetCellPositionFromNum(cellNum);
}