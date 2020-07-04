#pragma once

#include "Map.h"
#include "Character.h"
#include <string>
#include <vector>
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;

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

struct ItemData {
	std::string name;
	std::string description;
	int id;
	int catId;
	int effect;
};

class MainModel
{
public:
	// Constructeur et destructeur
	MainModel();
	~MainModel();

	// Fonction d'initalisation
	void init();

	// Sous fonctions d'initialisation
	void itemInit();
	void pkmnInit();

	// Getters 
	Character& getCharacter();
	Map& getMap();
	GameState& getGameState();

	// Donnéees 
	std::vector <ItemData> itemData;
	//std::vector <PkmnData> pkmnData;

private:
	Map map;
	Character character;

	GameState gameState;

	

	

};

