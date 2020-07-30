#include "Model.h"

void Model::init() {
	gameState.mapMode = true;
	gameState.menuMode = false;

	itemInit();
	pkmnInit();
	atkInit();
}

Character& Model::getCharacter() { return character; }
Map& Model::getMap() { return map; }
GameState& Model::getGameState() { return gameState; }

void Model::itemInit() {
	std::ifstream input("assets/data/items.json");
	json jsonFile;
	jsonFile = json::parse(input);

	for (unsigned int i=0 ; i<jsonFile.size() ; i++) {
		ItemData item;
		std::string index = std::to_string(i);
		item.id = jsonFile[index]["id"].get<int>();
		item.cat_id = jsonFile[index]["category"].get<int>();
		item.effect = jsonFile[index]["effect"].get<int>();
		item.name = jsonFile[index]["name"].get<std::string>();
		item.description = jsonFile[index]["description"].get<std::string>();

		itemData.push_back(item);
	}
}

void Model::pkmnInit() {
	std::ifstream input("assets/data/pokemons.json");
	json jsonFile;
	jsonFile = json::parse(input);

	for (unsigned int i = 0; i < jsonFile.size(); i++) {
		PkmnData pkmn;
		std::string index = std::to_string(i+1);
		pkmn.name = jsonFile[index]["name"].get<std::string>();
		pkmn.type1 = typeToInt(jsonFile[index]["type1"].get<std::string>());
		pkmn.type2 = typeToInt(jsonFile[index]["type2"].get<std::string>());
		pkmn.pokedex_entry = jsonFile[index]["pokedex_entries"].get<std::string>();
		pkmn.gender_ratio = jsonFile[index]["gender_ratio"].get<float>();
		pkmn.catch_rate = jsonFile[index]["catch_rate"].get<int>();
		pkmn.height = jsonFile[index]["height"].get<std::string>();
		pkmn.weight = jsonFile[index]["weight"].get<std::string>();
		pkmn.base_stats[0] = jsonFile[index]["base_stats"]["hp"].get<int>();
		pkmn.base_stats[1] = jsonFile[index]["base_stats"]["atk"].get<int>();
		pkmn.base_stats[2] = jsonFile[index]["base_stats"]["def"].get<int>();
		pkmn.base_stats[3] = jsonFile[index]["base_stats"]["atk_sp"].get<int>();
		pkmn.base_stats[4] = jsonFile[index]["base_stats"]["def_sp"].get<int>();
		pkmn.base_stats[5] = jsonFile[index]["base_stats"]["speed"].get<int>();
		pkmn.category = jsonFile[index]["category"].get<std::string>();
		pkmn.color = jsonFile[index]["color"].get<std::string>();
		pkmn.leveling_rate = jsonFile[index]["leveling_rate"].get<std::string>();
		pkmn.exp_yield = jsonFile[index]["exp_yield"].get<int>();
		pkmn.ev_yield[0] = jsonFile[index]["ev_yield"]["hp"].get<int>();
		pkmn.ev_yield[1] = jsonFile[index]["ev_yield"]["atk"].get<int>();
		pkmn.ev_yield[2] = jsonFile[index]["ev_yield"]["def"].get<int>();
		pkmn.ev_yield[3] = jsonFile[index]["ev_yield"]["atk_sp"].get<int>();
		pkmn.ev_yield[4] = jsonFile[index]["ev_yield"]["def_sp"].get<int>();
		pkmn.ev_yield[5] = jsonFile[index]["ev_yield"]["speed"].get<int>();

		pkmnData.push_back(pkmn);
	}
}

// TO DO
void Model::atkInit() {
	return;
}

Model::Model() {}
Model::~Model() {}

int Model::typeToInt(std::string type) {
	if (type == "Acier")
		return 1;
	else if (type == "Combat")
		return 2;
	else if (type == "Dragon")
		return 3;
	else if (type == "Eau")
		return 4;
	else if (type == "Electrik")
		return 5;
	else if (type == "Fee")
		return 6;
	else if (type == "Feu")
		return 7;
	else if (type == "Glace")
		return 8;
	else if (type == "Insecte")
		return 9;
	else if (type == "Normal")
		return 10;
	else if (type == "Plante")
		return 11;
	else if (type == "Poison")
		return 12;
	else if (type == "Psy")
		return 13;
	else if (type == "Roche")
		return 14;
	else if (type == "Sol")
		return 15;
	else if (type == "Spectre")
		return 16;
	else if (type == "Tenebre")
		return 17;
	else if (type == "Vol")
		return 18;
	else return 0;
}