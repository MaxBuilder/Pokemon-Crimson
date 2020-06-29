#pragma once
#include "Map.h"
#include "Character.h"

// Structure représentant les états du jeu
struct GameState {
	// Main gameStates
	bool mapMode;
	// bool combatMode 
	// bool inventoryMode
	// bool pokedexMode
	// bool teamMode

	// Map gameStates
	bool menuMode;
	int menuId;
};

class MainModel
{
public:
	// Constructeur et destructeur
	MainModel();
	~MainModel();

	// Fonction d'initalisation
	void init();

	Character& getCharacter();
	Map& getMap();
	GameState& getGameState();

private:
	Map map;
	Character character;
	GameState gameState;

	

	

};

