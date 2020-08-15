#pragma once
#include "Inventory.h"
#include "PkmnTeam.h"

class Character
{
public:
	// Player info
	std::string name;
	int noId;
	int money;
	int stars;
	int pokedex;
	int score;
	// TO DO : durée jeu, début

	// Logic
	int sizeX, sizeY;
	int posX, posY;
	int direction;
	int moveCount;
	bool sprint;

private:
	Inventory inventory;
	PkmnTeam team;

public:
	Inventory& getInventory();
	PkmnTeam& getPkmnTeam();

	// Constructeur et destructeur 
	Character();
	~Character();
};

