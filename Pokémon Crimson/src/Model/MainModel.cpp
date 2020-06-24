#include "MainModel.h"

void MainModel::init() {
	gameState.mapMode = true;
	gameState.menuMode = false;
}

Character& MainModel::getCharacter() { return character; }
Map& MainModel::getMap() { return map; }
GameState& MainModel::getGameState() { return gameState; }

MainModel::MainModel() {}
MainModel::~MainModel() {}