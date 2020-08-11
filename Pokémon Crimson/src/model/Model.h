#pragma once

#include "Map.h"
#include "Character.h"
#include <string>
#include <vector>
#include <fstream>
#include <array>
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

	// Pokédex gamestates
	bool pkdxMode;
	int pkdxId;

	// Team gamestates
	bool teamMode;
	int teamId;
	//bool teamMenu;
	//int teamMenuId;

};

struct ItemData {
	std::string name = "";
	std::string description = "";
	int id = 0;
	int cat_id = 0;
	int effect = 0;
};

struct PkmnData {
	std::string name = "";
	int type1 = 0, type2 = 0;
	std::string pokedex_entry = "";
	float gender_ratio = 0.f;
	int catch_rate = 0;
	std::string height = "", weight = "";
	std::array<int, 6> base_stats = {};
	std::string category = "";
	std::string color = "";
	std::string leveling_rate = "";
	int exp_yield = 0;
	std::array<int, 6> ev_yield = {};
};

class AtkData {

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
	std::vector <PkmnData> pkmnData;
	//std::vector <AtkData> atkData;

private:
	Map map;
	Character character;

	GameState gameState;

	// Fonction de conversion du type de string à int
	int typeToInt(std::string type);

	

	

};

