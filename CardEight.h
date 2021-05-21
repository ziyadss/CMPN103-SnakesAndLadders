#pragma once
#include "Card.h"
#include "RollDiceAction.h"

// [ CardEight ] Summary:
	// Its Apply() Function: Prevents the player from rolling the next turn
	// Its Parameters:  --> put it as a "data member" and read it in ReadCardParameters()
class CardEight :
	public Card
{
		// CardEignt Parameters: No parameters needed

	public:
		CardEight(const CellPosition& pos); // A Constructor takes card position

		virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEight

		virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player
		void Save(ofstream& OutFile, int Type, string fname);
		virtual void Load(ifstream& InFile, int Type, string fname);
		virtual ~CardEight(); // A Virtual Destructor
	};



