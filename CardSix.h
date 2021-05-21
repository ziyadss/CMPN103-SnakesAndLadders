#pragma once
#include "Card.h"
// [ CardSix ] Summary:
// Its Apply() Function: Moves the player backward the same number of steps that he just rolled
// Its Parameters:  --> put it as a "data member" and read it in ReadCardParameters()]

class CardSix :
	public Card
{
	// CardSix Parameters: No parameters needed

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix which is:  

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
														  // by moving the player forward the same number of steps we just rolled
	void Save(ofstream& OutFile, int Type, string fname);
	virtual void Load(ifstream& InFile, int Type, string fname);
	virtual ~CardSix(); // A Virtual Destructor
};



