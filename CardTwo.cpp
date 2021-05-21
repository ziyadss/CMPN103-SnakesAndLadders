#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardTwo: Enter its wallet amount ..."
	pOut->PrintMessage("New CardTwo: Enter its wallet amount ...");
	walletAmount = pIn->GetInteger(pOut);


	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Increment the wallet of pPlayer by the walletAmount data member of CardTwo
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
}
void CardTwo::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << " " << walletAmount << endl;
}

void CardTwo::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum;
	InFile >> cellNum >> walletAmount;

	position = CellPosition::GetCellPositionFromNum(cellNum);
}

void CardTwo::EditCard(Grid* pGrid) {
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	out->PrintMessage("Enter the new wallet amount... ");
	walletAmount = inp->GetInteger(out);

	while (walletAmount < 0) {


		out->PrintMessage("Invalid!Re-enter wallet amount... ");

		walletAmount = inp->GetInteger(out);


	}

	out->ClearStatusBar();
}