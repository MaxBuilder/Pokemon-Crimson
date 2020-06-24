#include "Controller.h"

void Controller::init(MainView& v, MainModel& m) {
	view = &v;
	model = &m;
	Character& chara = model->getCharacter();
	chara.posX = 45;
	chara.posY = 45;
	chara.sizeX = 32;
	chara.sizeY = 32;
	chara.direction = 0;
	chara.sprint = false;
	Map& map = model->getMap();
}

void Controller::update(int event) {
	GameState& gameState = model->getGameState();

	// Détection de l'état du jeu 
	if (gameState.mapMode)
		mapUpdate(event);

}

void Controller::mapUpdate(int event) {
	if (event == 5 and !model->getGameState().menuMode)
		model->getGameState().menuMode = true;

	model->getGameState().menuMode ? mapMenu(event) : mapMovement(event);
}

void Controller::mapMenu(int action) {
	if (action == 7)
		model->getGameState().menuMode = false;

	view->mapView.renderMenu();
	sf::sleep(sf::milliseconds(30));
}

void Controller::mapMovement(int movement) {
	Character& character = model->getCharacter(); // Syntax simplification

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
				view->mapView.render(-1, (character.posY * 16 + 16 - (i - 19.0f) * 0.8f));
				sf::sleep(sf::milliseconds(12));
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
				view->mapView.render(-1, (character.posY * 16 + 16 + (i - 19.0f) * 0.8f));
				sf::sleep(sf::milliseconds(12));
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
				view->mapView.render((character.posX * 16 + 16 - (i - 19.0f) * 0.8f));
				sf::sleep(sf::milliseconds(12));
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
				view->mapView.render((character.posX * 16 + 16 + (i - 19.0f) * 0.8f));
				sf::sleep(sf::milliseconds(12));
			}
		}
		clock.restart();
		break;



	case 11:
		if (character.direction == 1)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 1;
			sf::sleep(sf::milliseconds(10));
		}
		if (character.moveCount > 0) {
			character.posY--;
			character.sprint = true;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(-1, (character.posY * 16 + 16 - (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(10));
			}
		}
		clock.restart();
		break;

	case 12:
		if (character.direction == 0)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 0;
			sf::sleep(sf::milliseconds(10));
		}
		if (character.moveCount > 0) {
			character.posY++;
			character.sprint = true;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(-1, (character.posY * 16 + 16 + (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(10));
			}
		}
		clock.restart();
		break;

	case 13:
		if (character.direction == 2)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 2;
			sf::sleep(sf::milliseconds(10));
		}
		if (character.moveCount > 0) {
			character.posX--;
			character.sprint = true;
			for (float i = 0; i < 10; i++) {
				view->mapView.render((character.posX * 16 + 16 - (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(10));
			}
		}
		clock.restart();
		break;

	case 14:
		if (character.direction == 3)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 3;
			sf::sleep(sf::milliseconds(10));
		}
		if (character.moveCount > 0) {
			character.posX++;
			character.sprint = true;
			for (float i = 0; i < 10; i++) {
				view->mapView.render((character.posX * 16 + 16 + (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(10));
			}
		}
		clock.restart();
		break;
	}
	if (movement != 0) sf::sleep(sf::milliseconds(30));
	view->mapView.render();
}

Controller::Controller() {}
Controller::~Controller() {}