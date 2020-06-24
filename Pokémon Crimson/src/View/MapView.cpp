#include "MapView.h"

void MapView::init(sf::RenderWindow& target, MainModel& m) {
	window = &target;
	model = &m;
	load();
}

void MapView::renderMenu() {
	render();

	//window->clear();
	
	// Reset de la view
	window->setView(window->getDefaultView());

	sf::Sprite sp;
	sp.setTexture(menu);
	sp.setTextureRect(sf::IntRect(0, 0, 100, 180));
	sp.setPosition(0, 0);
	sp.setScale(5.0, 5.0);
	window->draw(sp);

	window->display();
}

void MapView::render(float x, float y) {
	// Camera coord selection
	float camPosX, camPosY;
	x == -1 ? camPosX = model->getCharacter().posX * 16 + 16 : camPosX = x;
	y == -1 ? camPosY = model->getCharacter().posY * 16 + 16 : camPosY = y;

	// Camera
	view.setCenter(camPosX+16, camPosY+16);
	view.setSize(256, 192);
	window->setView(view);

	window->clear();

	sf::Sprite sp;

	// Map
	sp.setTexture(map);
	window->draw(sp); 

	// getCharacter()
	model->getCharacter().sprint ? sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 4) * 32 + 128, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY))
		: sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 4) * 32, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY));
	sp.setTexture(character);
	//sp.setPosition(model->character.posX*16 + 8, model->character.posY*16);
	sp.setPosition(camPosX, camPosY);
	window->draw(sp);

	// Test menuMode
	

	window->display();
}

void MapView::load() {
	map.loadFromFile("data/city.png");
	character.loadFromFile("data/character.png");
	menu.loadFromFile("data/menu.png");
}

MapView::MapView() {}
MapView::~MapView() {}