#pragma once
#include "Card.h"

class CardFive : public Card

	// [ CardFive ] Summary:
	// Its Apply() Function: Move forward the same number of steps that you just rolled 
	//(if you reach a ladder or a snake at the end of moving forward, take it).
	// Its Parameters:  --> put it as a "data member" and read it in ReadCardParameters()

{
	// CardFive Parameters: No parameters needed


public:
	CardFive(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFive 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
														  // by moving the player forward the same number of steps we just rolled
	void Save(ofstream& OutFile, int Type, string fname);
	virtual void Load(ifstream& InFile, int Type, string fname);
	virtual ~CardFive(); // A Virtual Destructor
};

