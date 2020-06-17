#include "MapView.h"

void MapView::init(sf::RenderWindow& target, MainModel& m) {
	window = &target;
	model = &m;
	load();
}

void MapView::render(float x, float y) {
	// Camera coord selection
	float camPosX, camPosY;
	x == -1 ? camPosX = model->character.posX * 16 + 16 : camPosX = x;
	y == -1 ? camPosY = model->character.posY * 16 + 16 : camPosY = y;

	// Camera
	view.setCenter(camPosX, camPosY);
	view.setSize(256, 192);
	window->setView(view);

	window->clear();

	sf::Sprite sp;

	// Map
	sp.setTexture(map);
	window->draw(sp); 

	// Character
	sp.setTextureRect(sf::IntRect((model->character.moveCount % 4)*32, model->character.direction * 32, model->character.sizeX, model->character.sizeY));
	sp.setTexture(character);
	//sp.setPosition(model->character.posX*16 + 8, model->character.posY*16);
	sp.setPosition(camPosX, camPosY);
	window->draw(sp);

	window->display();
}

void MapView::load() {
	map.loadFromFile("data/city.png");
	character.loadFromFile("data/character.png");
}

MapView::MapView() {}
MapView::~MapView() {}