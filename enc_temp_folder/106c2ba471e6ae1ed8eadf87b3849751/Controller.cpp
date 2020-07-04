#include "Controller.h"

void Controller::init(MainView& v, MainModel& m) {
	view = &v;
	model = &m;
	model->init();

	// Test initialization, future serialization
	Character& chara = model->getCharacter();
	chara.posX = 45;
	chara.posY = 45;
	chara.sizeX = 32;
	chara.sizeY = 32;
	chara.direction = 0;
	chara.sprint = false;
	chara.getInventory().loadInventory();



	prevEvent = 0;
}

void Controller::update(int event) {
	GameState& gameState = model->getGameState();

	// D�tection de l'�tat du jeu 
	if (gameState.mapMode)
		mapUpdate(event);

}

// Fonction de mise � jour losque le joueur est dans la map
void Controller::mapUpdate(int event) {
	if (event == 5 and !model->getGameState().menuMode and prevEvent != 5) // Event "X"
		model->getGameState().menuMode = true;
	else if(model->getGameState().menuMode and event == 5 and prevEvent != 5) // Anti spam "X"
		model->getGameState().menuMode = false;

	model->getGameState().menuMode ? mapMenuUpdate(event) : mapMovementUpdate(event);

	prevEvent = event;
}

// Fonction de mise � jour en fonction d'un �v�nement dans le menu
void Controller::mapMenuUpdate(int action) {
	GameState& gameState = model->getGameState();

	if (action == 7) // Event "E"
		gameState.menuMode = false;

	else if (action == 1 and prevEvent != 1) { // Event "Z"
		gameState.menuId--;
		if (gameState.menuId < 0) gameState.menuId = 6;
	}

	else if (action == 2 and prevEvent != 2) { // Event "S"
		gameState.menuId++;
		if (gameState.menuId > 6) gameState.menuId = 0;
	}

	view->mapView.renderMenu();
	sf::sleep(sf::milliseconds(20));
}

// Fonction de d�placement dans la map en fonction d'un �venement
void Controller::mapMovementUpdate(int movement) {
	Character& character = model->getCharacter(); // Syntax simp.

	switch (movement) {
	case 0:
		if (clock.getElapsedTime().asMilliseconds() > 100) {
			character.moveCount = 0;
			character.sprint = false;
			}
		break;

	case 1:
		if (model->getCharacter().direction == 1)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 1;
			sf::sleep(sf::milliseconds(40));
		}
		if (character.moveCount > 0) {
			character.posY--;
			character.sprint = false;
			for (float i = 0; i < 20; i++) {
				view->mapView.render(-1, (character.posY * 16 + 16 - (i - 19.0f) * 0.8f), (i > 9));
				sf::sleep(sf::milliseconds(15));
			}
		}
		clock.restart();
		break;

	case 2:
		if (character.direction == 0)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 0;
			sf::sleep(sf::milliseconds(40));
		}
		if (character.moveCount > 0) {
			character.posY++;
			character.sprint = false;
			for (float i = 0; i < 20; i++) {
				view->mapView.render(-1, (character.posY * 16 + 16 + (i - 19.0f) * 0.8f), (i > 9));
				sf::sleep(sf::milliseconds(15));
			}
		}
		clock.restart();
		break;

	case 3:
		if (character.direction == 2)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 2;
			sf::sleep(sf::milliseconds(40));
		}
		if (character.moveCount > 0) {
			character.posX--;
			character.sprint = false;
			for (float i = 0; i < 20; i++) {
				view->mapView.render((character.posX * 16 + 16 - (i - 19.0f) * 0.8f), -1, (i > 9));
				sf::sleep(sf::milliseconds(15));
			}
		}
		clock.restart();
		break;

	case 4:
		if (character.direction == 3)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 3;
			sf::sleep(sf::milliseconds(40));
		}
		if (character.moveCount > 0) {
			character.posX++;
			character.sprint = false;
			for (float i = 0; i < 20; i++) {
				view->mapView.render((character.posX * 16 + 16 + (i - 19.0f) * 0.8f), -1, (i > 9));
				sf::sleep(sf::milliseconds(15));
			}
		}
		clock.restart();
		break;

	// Sprint

	case 11:
		if (character.direction != 1)
			character.direction = 1;
		
		character.posY--;
		character.sprint = true;
		for (float i = 0; i < 10; i++) {
			view->mapView.render(-1, (character.posY * 16 + 16 - (i - 9.0f) * 1.6f), (i < 4));
			if (i == 4) character.moveCount++;
			sf::sleep(sf::milliseconds(12));
		}
		clock.restart();
		break;

	case 12:
		if (character.direction != 0)
			character.direction = 0;

		character.posY++;
		character.sprint = true;
		for (float i = 0; i < 10; i++) {
			view->mapView.render(-1, (character.posY * 16 + 16 + (i - 9.0f) * 1.6f), (i < 4));
			if (i == 4) character.moveCount++;
			sf::sleep(sf::milliseconds(12));
		}
		clock.restart();
		break;

	case 13:
		if (character.direction != 2)
			character.direction = 2;
		
		character.posX--;
		character.sprint = true;
		for (float i = 0; i < 10; i++) {
			view->mapView.render((character.posX * 16 + 16 - (i - 9.0f) * 1.6f), -1, (i < 4));
			if (i == 4) character.moveCount++;
			sf::sleep(sf::milliseconds(12));
		}
		clock.restart();
		break;

	case 14:
		if (character.direction != 3)
			character.direction = 3;

		character.posX++;
		character.sprint = true;
		for (float i = 0; i < 10; i++) {
			view->mapView.render((character.posX * 16 + 16 + (i - 9.0f) * 1.6f), -1, (i < 4));
			if (i == 4) character.moveCount++;
			sf::sleep(sf::milliseconds(12));
		}
		clock.restart();
		break;
	}
	if (movement != 0) sf::sleep(sf::milliseconds(30));
	view->mapView.render();
}

Controller::Controller() {}
Controller::~Controller() {}