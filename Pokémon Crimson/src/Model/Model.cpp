#include "Model.h"

void Model::init() {
	gameState.mapMode = true;
	gameState.menuMode = false;

	itemInit();
	//pkmnInit();
	//atkInit();
}

Character& Model::getCharacter() { return character; }
Map& Model::getMap() { return map; }
GameState& Model::getGameState() { return gameState; }

void Model::itemInit() {
	std::ifstream input("data/items.json");
	json jsonFile;
	jsonFile = json::parse(input);

	for (unsigned int i=0 ; i<jsonFile.size() ; i++) {
		ItemData item;
		std::string num = std::to_string(i);
		item.id = jsonFile[num]["id"].get<int>();
		item.catId = jsonFile[num]["category"].get<int>();
		item.effect = jsonFile[num]["effect"].get<int>();
		item.name = jsonFile[num]["name"].get<std::string>();
		item.description = jsonFile[num]["description"].get<std::string>();

		itemData.push_back(item);
	}

	return;
}

Model::Model() {}
Model::~Model() {}