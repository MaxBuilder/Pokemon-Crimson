#pragma once
#include "Map.h"
#include "Character.h"

class MainModel
{
public:
	void init();

	Map map;
	Character character;

	// Constrcteur et destructeur
	MainModel();
	~MainModel();

};

