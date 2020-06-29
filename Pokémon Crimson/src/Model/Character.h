#pragma once
#include "Inventory.h"

class Character
{
public:
	// bool bGender;
	int sizeX, sizeY;
	int posX, posY;
	int direction;
	int moveCount;
	bool sprint;

private:
	Inventory inventory;
	// PkmnTeam team;

};

