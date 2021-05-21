#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();

	// 2- print to a descriptive message to the user like:"New CardEight: Prevents the player from rolling the next turn"
	pOut->PrintMessage("New CardEight: Prevents the player from rolling the next turn");

	// 3- Clear the status bar
	pOut->ClearStatusBar();

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Prevents the player from rolling the next turn
	pPlayer = pGrid->GetCurrentPlayer();
	pPlayer->SetPlay(false);
	
}

void CardEight::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << " " << endl;
}
void CardEight::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum;
	InFile >> cellNum;

	position = CellPosition::GetCellPositionFromNum(cellNum);
}