#include "Ladder.h"

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if(endCellPos.HCell()!=-1||endCellPos.VCell()!=-1)
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}
bool Ladder::VerticalLadder(CellPosition& startCellPos, CellPosition& endCellPos)
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
bool Ladder::AscendingLadder(CellPosition& startCellPos, CellPosition& endCellPos)
{
	int startcell = startCellPos.GetCellNumFromPosition(startCellPos);
	int EndCell = endCellPos.GetCellNumFromPosition(endCellPos);

	if (EndCell < startcell)
	{
		startCellPos.SetVCell(-1);
		startCellPos.SetHCell(-1);
		endCellPos.SetVCell(-1);
		endCellPos.SetHCell(-1);
		return true;
	}
	return false;
}
bool Ladder::startCellLadder(CellPosition& startCellPos)
{
	if (startCellPos.VCell() == 0)
	{
		startCellPos.SetVCell(-1);
		startCellPos.SetHCell(-1);
		return true;
	}
	return false;
}
void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}
bool Ladder::IsOverlapping(GameObject* newObj)
{
	Ladder* newLadder= dynamic_cast<Ladder*>(newObj);
	if (newLadder)
	{
		if (position.HCell() == newLadder->GetPosition().HCell())
		{
			for (int i = position.VCell(); i >= endCellPos.VCell(); i--) // to allocate cells from bottom up
			{
				if (i == newLadder->GetPosition().VCell() || i == newLadder->GetEndPosition().VCell())
				{
					return true;
				}
			}
		}
		return false;

	}
}
void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}

void Ladder::Save(ofstream& OutFile, int Type, string fname) {
	if (Type != 0)
		return;
	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}
void Ladder::Load(ifstream& InFile, int Type, string fname) {
	if (Type != 0)
		return;
	int cellNum, endCellNum;
	InFile >> cellNum >> endCellNum;

	position = CellPosition::GetCellPositionFromNum(cellNum);
	endCellPos = CellPosition::GetCellPositionFromNum(endCellNum);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
