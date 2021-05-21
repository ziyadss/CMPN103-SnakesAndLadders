#include "CardThirteen.h"
CardThirteen::CardThirteen(const CellPosition& pos) : Card(pos) {
	cardNumber = 13;
}
CardThirteen::~CardThirteen(void)
{
}
int CardThirteen::price = 0;
int CardThirteen::fees = 0;
Player* CardThirteen::pPlayerOwner = NULL;

void CardThirteen::ReadCardParameters(Grid* pGrid) {
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	if (price == 0 && fees == 0) {
		out->PrintMessage("New CardThirteen: Enter its price...");
		price = inp->GetInteger(out);
		while (price < 0) {
			out->PrintMessage("Invalid!Re-enter...");
			price = inp->GetInteger(out);
		}
		out->PrintMessage("Enter fee of station...");
		fees = inp->GetInteger(out);
		while (fees < 0) {
			out->PrintMessage("Invalid!Re-enter");
			fees = inp->GetInteger(out);
			out->ClearStatusBar();
		}
		// [ Note ]:
		// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
		// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
		// to be able to perform his Apply() action
	}
}

void CardThirteen::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Card::Apply(pGrid, pPlayer);
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	if (pPlayerOwner == NULL) {
		if (pPlayer->GetWallet() < price) {
			out->PrintMessage("Not enough money to buy this station");
			return;
		}
		else {
			out->PrintMessage("Do you want to buy this station? Y/N");
			string s = inp->GetSrting(out);
			if (s == "Y") {
				int w = pPlayer->GetWallet();
				w = w - price;
				pPlayer->SetWallet(w);
				pPlayerOwner = pPlayer;
			}
			if (s == "N")
				return;
		}
	}
	if (pPlayerOwner == pPlayer) {
		out->PrintMessage("Player is owner os station");
	}

}
void CardThirteen::EditCard(Grid* pGrid) {
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	out->PrintMessage("Enter price of station...");
	price = inp->GetInteger(out);
	while (price < 0) {
		out->PrintMessage("Invalid!Re-enter price...");
		price = inp->GetInteger(out);
	}
	out->PrintMessage("Enter fees for this station...");
	fees = inp->GetInteger(out);
	while (fees < 0) {
		out->PrintMessage("Invalid!Re-enter fees...");
		fees = inp->GetInteger(out);
	}
	out->ClearStatusBar();
}
void CardThirteen::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << " " << price << " " << fees << endl;
}
void CardThirteen::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum;
	InFile >> cellNum >> price >> fees;

	position = CellPosition::GetCellPositionFromNum(cellNum);
}