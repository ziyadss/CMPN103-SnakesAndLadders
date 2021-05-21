#include "CardNine.h"
CardNine::CardNine(const CellPosition& pos) :Card(pos)
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	pGrid->GetOutput()->PrintMessage("Click a cell to move to");
	Celltomoveto = pGrid->GetInput()->GetCellClicked();
	while (!Celltomoveto.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cell, Click another");
		Celltomoveto = pGrid->GetInput()->GetCellClicked();
	}
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->UpdatePlayerCell(pPlayer, Celltomoveto);
	GameObject* gO = pPlayer->GetCell()->GetGameObject();
	if (gO)
		gO->Apply(pGrid, pPlayer);

}
void CardNine::Save(ofstream& OutFile, int Type, string fname)
{
	if (Type != 2)
		return;
	OutFile << cardNumber << " " << position.GetCellNum() << Celltomoveto.GetCellNum() << endl;
}

void CardNine::Load(ifstream& InFile, int Type, string fname)
{
	if (Type != 2)
		return;
	int cellNum, Celltomovetonum;
	InFile >> cellNum >> Celltomovetonum ;

	position = CellPosition::GetCellPositionFromNum(cellNum);
	Celltomoveto = CellPosition::GetCellPositionFromNum(Celltomovetonum);
}
CardNine::~CardNine()
{

}