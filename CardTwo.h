#pragma once

#include "Card.h"

class CardTwo : public Card
{
	
	int walletAmount; 

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	void Save(ofstream& OutFile, int Type, string fname);
	virtual void Load(ifstream& InFile, int Type, string fname);
	void EditCard(Grid* pGrid);
	virtual ~CardTwo(); // A Virtual Destructor
};

#pragma once
