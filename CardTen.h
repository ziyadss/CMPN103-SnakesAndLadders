#pragma once
#include "Card.h"
class CardTen :
	public Card
{
	static int price;
	static int fees;
	
public:
	static Player* pPlayerOwner;
	CardTen(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTen which is: price & fees

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTen on the passed Player
													  // by deducting fees from his wallet
	void EditCard(Grid* pGrid);
	void Save(ofstream& OutFile, int Type, string fname);
	virtual void Load(ifstream& InFile, int Type, string fname);
	virtual ~CardTen(); // A Virtual Destructor
};

