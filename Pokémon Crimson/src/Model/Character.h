#pragma once
#include "Inventory.h"

class Character
{
public:
	// Player info
	std::string name;
	int noId;
	int money;
	int stars;
	// int pokedex; // Nombre de pok�mons captur�s
	// int score;	// ???
	// TO DO : dur�e jeu, d�but

	// Logic
	int sizeX, sizeY;
	int posX, posY;
	int direction;
	int moveCount;
	bool sprint;

private:
	Inventory inventory;
	// PkmnTeam team;

public:
	Inventory& getInventory();
	//PkmnTeam& getPkmnTeam();

	// Constructeur et destructeur 
	Character();
	~Character();
};

