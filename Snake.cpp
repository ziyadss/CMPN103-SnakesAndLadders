#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.HCell() != -1 || endCellPos.VCell() != -1)
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}
bool Snake::VerticalSnake(CellPosition& startCellPos, CellPosition& endCellPos)
{
	if (startCellPos.HCell() != endCellPos.HCell())
	{
		startCellPos.SetVCell(-1);
		startCellPos.SetHCell(-1);
		endCellPos.SetVCell(-1);
		endCellPos.SetHCell(-1);
		return true;
	}
	return false;
}
bool Snake::DescendingSnake(CellPosition& startCellPos, CellPosition& endCellPos)
{
	int startcell = startCellPos.GetCellNumFromPosition(startCellPos);
	int EndCell = endCellPos.GetCellNumFromPosition(endCellPos);

	if (EndCell > startcell)
	{
		startCellPos.SetVCell(-1);
		startCellPos.SetHCell(-1);
		endCellPos.SetVCell(-1);
		endCellPos.SetHCell(-1);
		return true;
	}
	return false;
}
bool Snake::startCellSnake(CellPosition& startCellPos)
{
	if (startCellPos.VCell() == 8)
	{
		startCellPos.SetVCell(-1);
		startCellPos.SetHCell(-1);
		return true;
	}
	return false;

}
void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}
bool Snake::IsOverlapping(GameObject* newObj)
{
	Snake* newSnake = dynamic_cast<Snake*>(newObj);
	if (newSnake)
	{
		if (position.HCell() == newSnake->GetPosition().HCell())
		{
			for (int i = endCellPos.VCell(); i >= position.VCell(); i--) // to allocate cells from bottom up
			{
				if (i == newSnake->GetPosition().VCell() || i == newSnake->GetEndPosition().VCell())
				{
					return true;
				}
			}
		}

	}
	return false;
}

void Snake::Save(ofstream& OutFile, int Type, string fname) {
	if (Type != 1)
		return;
	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

void Snake::Load(ifstream& InFile, int Type, string fname) {
	if (Type != 1)
		return;
	int cellNum, endCellNum;
	InFile >> cellNum >> endCellNum;

	position = CellPosition::GetCellPositionFromNum(cellNum);
	endCellPos = CellPosition::GetCellPositionFromNum(endCellNum);
}
CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
