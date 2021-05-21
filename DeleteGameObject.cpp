#include "DeleteGameObject.h"
#include "Grid.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{

}

void DeleteGameObject::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	out->PrintMessage("Click a cell to delete the object from");
	objPosition = inp->GetCellClicked();
	if (!objPosition.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cell, operation cancelled");
		return;
	}

}

void DeleteGameObject::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(objPosition);
}

DeleteGameObject::~DeleteGameObject()
{

}

