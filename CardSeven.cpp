#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();

	// 2- print to a descriptive message to the user like:"New CardFive: Moves farward the same number or steps you just rolled"
	pOut->PrintMessage("New CardSeven: Gives you another dice roll");

	// 3- Clear the status bar
	pOut->ClearStatusBar();

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2-  Give the player another dice roll
	for (int i = 0; i < MaxPlayerCount - 1; i++)
		pGrid->AdvanceCurrentPlayer();

}
void CardSeven::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << " " << endl;
}

void CardSeven::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum;
	InFile >> cellNum;

	position = CellPosition::GetCellPositionFromNum(cellNum);
}