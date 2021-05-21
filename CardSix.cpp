#include "CardSix.h"


CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	Player* pPlayer;

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();

	// 2- print to a descriptive message to the user like:"New CardFive: Moves the player backward the same number of steps that he just rolled"
	pOut->PrintMessage("New CardSix: Moves the player backward the same number of steps that he just rolled");

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// 2- Moves the player backward the same number of steps that he just rolled
	int JustRolledDiceNumber = pPlayer->GetjustRolledDiceNum();
	int cellnumber = position.GetCellNumFromPosition(position);
	int newCellNumber = cellnumber - JustRolledDiceNumber;
	CellPosition pos = position.GetCellPositionFromNum(newCellNumber);
	pGrid->UpdatePlayerCell(pPlayer, pos);

}
void CardSix::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardSix::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum;
	InFile >> cellNum;

	position = CellPosition::GetCellPositionFromNum(cellNum);
}