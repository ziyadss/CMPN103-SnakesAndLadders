#include "CardFour.h"
#include "Snake.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}
void CardFour::ReadCardParameters(Grid* pGrid)
{

}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Snake* pSnake = pGrid->GetNextSnake(position);
	if (pSnake == NULL)
		return;
	CellPosition posSnake = pSnake->GetPosition();
	pGrid->UpdatePlayerCell(pPlayer, posSnake);
	pSnake->Apply(pGrid, pPlayer);
}
void CardFour::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardFour::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum;
	InFile >> cellNum;

	position = CellPosition::GetCellPositionFromNum(cellNum);
}
CardFour::~CardFour(void)
{
}