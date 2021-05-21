#pragma once
#include "Card.h"
#include "RollDiceAction.h"

// [ CardSeven ] Summary:
	// Its Apply() Function: Gives the player another dice roll
	// Its Parameters:  --> put it as a "data member" and read it in ReadCardParameters()
class CardSeven :
	public Card
{
	// CardSeven Parameters: No parameters needed

	public:
		CardSeven(const CellPosition& pos); // A Constructor takes card position

		virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSeven 

		virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player
		void Save(ofstream& OutFile, int Type, string fname);
		virtual void Load(ifstream& InFile, int Type, string fname);
		virtual ~CardSeven(); // A Virtual Destructor
	};


