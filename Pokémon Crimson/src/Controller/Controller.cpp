#include "Controller.h"

void Controller::init(MainView& v, MainModel &m) {
	view = &v;
	model = &m;
	Character& chara = model->character;
	chara.posX = 45;
	chara.posY = 45;
	chara.sizeX = 32;
	chara.sizeY = 32;
	chara.direction = 0;
	chara.run = false;
	Map& map = model->map;
}

void Controller::update(int event) {
	switch (event) {
	case 0:
		if(clock.getElapsedTime().asMilliseconds() > 100 )
			model->character.moveCount = 0;
		break;

	case 1:
		if (model->character.direction == 1)
			model->character.moveCount++;
		else {
			model->character.moveCount = 0;
			model->character.direction = 1;
			sf::sleep(sf::milliseconds(40));
		}
		if (model->character.moveCount > 0) {
			model->character.posY--;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(false, -1, (model->character.posY * 16 + 16 - (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(20));
			}
		}
		clock.restart();
		break;

	case 2:
		if (model->character.direction == 0)
			model->character.moveCount++;
		else {
			model->character.moveCount = 0;
			model->character.direction = 0;
			sf::sleep(sf::milliseconds(40));
		}
		if (model->character.moveCount > 0) {
			model->character.posY++;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(false, -1, (model->character.posY * 16 + 16 + (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(20));
			}
		}
		clock.restart();
		break;

	case 3:
		if (model->character.direction == 2)
			model->character.moveCount++;
		else {
			model->character.moveCount = 0;
			model->character.direction = 2;
			sf::sleep(sf::milliseconds(40));
		}
		if (model->character.moveCount > 0) {
			model->character.posX--;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(false, (model->character.posX * 16 + 16 - (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(20));
			}
		}
		clock.restart();
		break;

	case 4:
		if (model->character.direction == 3)
			model->character.moveCount++;
		else {
			model->character.moveCount = 0;
			model->character.direction = 3;
			sf::sleep(sf::milliseconds(40));
		}
		if (model->character.moveCount > 0) {
			model->character.posX++;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(false, (model->character.posX * 16 + 16 + (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(20));
			}
		}
		clock.restart();
		break;



	case 11:
		if (model->character.direction == 1)
			model->character.moveCount++;
		else {
			model->character.moveCount = 0;
			model->character.direction = 1;
			sf::sleep(sf::milliseconds(10));
		}
		if (model->character.moveCount > 0) {
			model->character.posY--;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(true, -1, (model->character.posY * 16 + 16 - (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(12));
			}
		}
		clock.restart();
		break;

	case 12:
		if (model->character.direction == 0)
			model->character.moveCount++;
		else {
			model->character.moveCount = 0;
			model->character.direction = 0;
			sf::sleep(sf::milliseconds(10));
		}
		if (model->character.moveCount > 0) {
			model->character.posY++;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(true, -1, (model->character.posY * 16 + 16 + (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(12));
			}
		}
		clock.restart();
		break;

	case 13:
		if (model->character.direction == 2)
			model->character.moveCount++;
		else {
			model->character.moveCount = 0;
			model->character.direction = 2;
			sf::sleep(sf::milliseconds(10));
		}
		if (model->character.moveCount > 0) {
			model->character.posX--;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(true, (model->character.posX * 16 + 16 - (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(12));
			}
		}
		clock.restart();
		break;

	case 14:
		if (model->character.direction == 3)
			model->character.moveCount++;
		else {
			model->character.moveCount = 0;
			model->character.direction = 3;
			sf::sleep(sf::milliseconds(10));
		}
		if (model->character.moveCount > 0) {
			model->character.posX++;
			for (float i = 0; i < 10; i++) {
				view->mapView.render(true, (model->character.posX * 16 + 16 + (i - 9.0f) * 1.6f));
				sf::sleep(sf::milliseconds(12));
			}
		}
		clock.restart();
		break;
	}
	if (event != 0) sf::sleep(sf::milliseconds(30));
	view->mapView.render(false);

}
// 1 haut, 2 bas, 3 gauche, 4 droite (provisoire)

Controller::Controller() {}
Controller::~Controller() {}