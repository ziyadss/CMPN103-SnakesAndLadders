#pragma once
#include "Card.h"
class CardThree : public Card

{ 

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
													  // by moving the player forward the same number of steps we just rolled
	void Save(ofstream& OutFile, int Type, string fname);
	virtual void Load(ifstream& InFile, int Type, string fname);
	virtual ~CardThree(); // A Virtual Destructor
};



