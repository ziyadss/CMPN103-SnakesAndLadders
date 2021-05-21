#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	if ((v >= 0) && (v < NumVerticalCells))
	{
		vCell = v;
		return true;
	}
	else
		return false;
	
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	if ((h >= 0) && (h < NumHorizontalCells))
	{
		hCell = h;
		return true;
	}
	else
		return false;
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	CellPosition cp;
	if (cp.SetVCell(vCell) == true && cp.SetHCell(hCell) == true)
		return true;
	else
		return false;
	///TODO: Implement this function as described in the .h file

}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int cellNumber;
	cellNumber = (NumVerticalCells - cellPosition.VCell() - 1) * NumHorizontalCells + cellPosition.HCell() + 1;

	return cellNumber; 
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	if (cellNum < 0)
		cellNum = 0;
	if (cellNum > 99)
		cellNum = 99;
	int vertical = (NumVerticalCells*NumHorizontalCells - cellNum) / NumHorizontalCells;
	int horizontal = cellNum - ((NumVerticalCells - vertical - 1) * NumHorizontalCells) - 1;
	position.SetVCell(vertical);
	position.SetHCell(horizontal);

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	
	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file



	// Note: this function updates the data members (vCell and hCell) of the calling object
	int num = GetCellNum() + addedNum;
	*this = GetCellPositionFromNum(num);
}