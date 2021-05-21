#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3; 
}
void CardThree::ReadCardParameters(Grid* pGrid)
{

}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Ladder* pLadder=pGrid->GetNextLadder(position);
	if (pLadder == NULL)
		return;
	CellPosition posLad=pLadder->GetPosition();
	pGrid->UpdatePlayerCell(pPlayer, posLad);
	pLadder->Apply(pGrid, pPlayer);
}
void CardThree::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardThree::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum;
	InFile >> cellNum;

	position = CellPosition::GetCellPositionFromNum(cellNum);
}
CardThree::~CardThree(void)
{
}