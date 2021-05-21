#pragma once
#include "GameObject.h"
class Snake : public GameObject  // inherited from GameObject
	{
		// Note: the "position" data member inherited from the GameObject class is used as the Snakes's "Start Cell Position"

		CellPosition endCellPos; // here is the Snake's End Cell Position

	public:

		Snake (const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

		virtual void Draw(Output* pOut) const; // Draws a Snake from its start cell to its end cell

		virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the Snake by moving player to Snake's end cell
		bool VerticalSnake(CellPosition& startCellPos, CellPosition& endCellPos);
		bool DescendingSnake(CellPosition& startCellPos, CellPosition& endCellPos);
		bool startCellSnake(CellPosition& startCellPos);
		virtual void Save(ofstream& OutFile, int Type, string fname);
		virtual void Load(ifstream& InFile, int Type, string fname);

		virtual bool IsOverlapping(GameObject* newObj);
		CellPosition GetEndPosition() const; // A getter for the endCellPos data member

		virtual ~Snake(); // Virtual destructor
	};


