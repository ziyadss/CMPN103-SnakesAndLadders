#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "Player.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}
bool Grid::IsOverlapping(GameObject* newObj)
{
	CellPosition Pos=newObj->GetPosition();
	CellPosition EndPos;
	
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			if (GameObject* hasObject = CellList[i][j]->GetGameObject())
			{
				if (Ladder* oldLadder = dynamic_cast<Ladder*>(hasObject))
				{
					if (Ladder* newLadder = dynamic_cast<Ladder*>(newObj))
					{
						if (newLadder->IsOverlapping(oldLadder))
							return true;
					}
				}
				if (Snake* oldSnake = dynamic_cast<Snake*>(hasObject))
				{
					if (Snake* newSnake = dynamic_cast<Snake*>(newObj))
					{
						if (newSnake->IsOverlapping(oldSnake))
							return true;
					}
				}
			}
		}
	}
		
	
	return false;
}


// ========= Setters and Getters Functions =========


Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========
Card* Grid::GetCard(const CellPosition& position)
{
	return CellList[position.VCell()][position.HCell()]->HasCard();
}

Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder* Grid::GetNextLadder(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			Ladder* pLadder = CellList[i][j]->HasLadder();
			if (pLadder != NULL)
				return pLadder;

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake* Grid::GetNextSnake(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			Snake* pSnake = CellList[i][j]->HasSnake();
			if (pSnake != NULL)
				return pSnake;
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::SaveAll(ofstream& OutFile, int Type, string fname)
{
	int count = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			switch (Type)
			{
			case 0:	if (CellList[i][j]->HasLadder())
				count++;
				break;
			case 1: if (CellList[i][j]->HasLadder())
				count++;
				break;
			case 2: if (CellList[i][j]->HasCard())
				count++;
				break;
			}

		}
	}
	OutFile << count << endl;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			if (CellList[i][j]->GetGameObject())
				CellList[i][j]->GetGameObject()->Save(OutFile, Type, fname);
		}
	}
}

void Grid::LoadAll(ifstream& InFile, int Type, string fname)
{
	if (Type == 0)
	{
		int count;
		InFile >> count;
		for (int i = 0; i < count; i++)
		{
			Ladder* pL = new Ladder(CellPosition::GetCellPositionFromNum(6), CellPosition::GetCellPositionFromNum(39));
			pL->Load(InFile, Type, fname);
			AddObjectToCell(pL);
		}

	}
	if (Type == 1)
	{
		int count;
		InFile >> count;
		for (int i = 0; i < count; i++)
		{
			Snake* pS = new Snake(CellPosition::GetCellPositionFromNum(92), CellPosition::GetCellPositionFromNum(48));
			pS->Load(InFile, Type, fname);
			AddObjectToCell(pS);
		}

	}
	if (Type == 2)
	{
		int count;
		InFile >> count;
		for (int i = 0; i < count; i++)
		{
			int cardNum;
			InFile >> cardNum;
			Card* pCard;
			CellPosition cardPosition = CellPosition::GetCellPositionFromNum(13);
			switch (cardNum)
			{
			case 1:
				pCard = new CardOne(cardPosition);
				break;

			case 2:
				pCard = new CardTwo(cardPosition);
				break;
			case 3:
				pCard = new CardThree(cardPosition);
				break;
			case 4:
				pCard = new CardFour(cardPosition);
				break;
			case 5:
				pCard = new CardFive(cardPosition);
				break;
			case 6:
				pCard = new CardSix(cardPosition);
				break;
			case 7:
				pCard = new CardSeven(cardPosition);
				break;
			case 8:
				pCard = new CardEight(cardPosition);
				break;
			case 9:
				pCard = new CardNine(cardPosition);
				break;
			case 10:
				pCard = new CardTen(cardPosition);
				break;
			case 11:
				pCard = new CardEleven(cardPosition);
				break;
			case 12:
				pCard = new CardTwelve(cardPosition);
				break;
			case 13:
				pCard = new CardThirteen(cardPosition);
				break;
			case 14:
				pCard = new CardFourteen(cardPosition);
				break;

			}
			pCard->Load(InFile, Type, fname);
			AddObjectToCell(pCard);
		}
	}
}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}