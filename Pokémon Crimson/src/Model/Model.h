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

	// Menu gamestates
	bool menuMode;
	int menuId;

	// Inventory gamestates
	bool invMode;
	int invCatId;
	int invItemId;
	int invMaxItemId;
	bool invMenu;
	int invMenuId;

	// Trainer card gamestates
	bool cardMode;
};

struct ItemData {
	std::string name = "";
	std::string description = "";
	int id = 0;
	int catId = 0;
	int effect = 0;
};

class Model
{
public:
	// Constructeur et destructeur
	Model();
	~Model();

	// Fonction d'initalisation
	void init();

	// Sous fonctions d'initialisation
	void itemInit();
	void pkmnInit();
	void atkInit();

	// Getters 
	Character& getCharacter();
	Map& getMap();
	GameState& getGameState();

	// Donnéees 
	std::vector <ItemData> itemData;
	//std::vector <PkmnData> pkmnData;
	//std::vector <AtkData> atkData;

private:
	Map map;
	Character character;

	GameState gameState;

	

	

};

