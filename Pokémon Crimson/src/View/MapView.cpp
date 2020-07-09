#include "MapView.h"

void MapView::init(sf::RenderWindow& target, MainModel& m) {
	window = &target;
	model = &m;
	load();
}

void MapView::renderBag() {
	int catId = model->getGameState().invCatId;
	window->clear();

	sf::Sprite sp;
	sp.setTexture(bag);

	// Background
	drawImage(sp, 0, 0, 256, 192);

	// Text
	// drawText

	// Panel
	drawImage(sp, 0, 326, 142, 126, 540.f, 35.f);

	// Bag icon
	drawImage(sp, 0 + (catId % 4) * 56, 194 + 58 * (catId > 3), 56, 58, 100.f, 110.f);

	// Small icon + selector
	drawImage(sp, 0 + catId * 12, 312, 12, 12, 35.f + catId * 55.f, 450.f);
	drawImage(sp, 150, 454, 14, 14, 30.f + catId * 55.f, 445);

	window->display();
}

void MapView::renderMenu() {
	renderWorld();

	// Reset de la view
	window->setView(window->getDefaultView());

	int id = model->getGameState().menuId;
	sf::Sprite sp;
	sp.setTexture(menu);

	// Menu, selector, icons
	drawImage(sp, 0, 0, 100, 180, 760.f, 20.f);
	drawImage(sp, 102, 2, 92, 26, 780.f, 45 + id * 120.f);
	drawImage(sp, 102 + (id >= 4) * 24, 32 + (id % 4) * 24, 24, 24, 800.f, 50.f + id * 120.f);

	window->display();
}

void MapView::renderWorld(float x, float y, bool second) {
	// Camera coord selection
	float camPosX, camPosY;
	x == -1 ? camPosX = model->getCharacter().posX * 16.f + 16 : camPosX = x;
	y == -1 ? camPosY = model->getCharacter().posY * 16.f + 16 : camPosY = y;

	// Camera
	view.setCenter(camPosX+16, camPosY+16);
	view.setSize(256, 192);
	window->setView(view);

	window->clear();
	
	// Map
	sf::Sprite sp;
	sp.setTexture(map);
	window->draw(sp); 

	// Character
	//model->getCharacter().sprint ? sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 4) * 32 + 128, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY)) : sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 4) * 32, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY));
	if (model->getCharacter().moveCount > 0) {
		if (!model->getCharacter().sprint)
			second ? sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 2) * 64 + 32, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY)) : sp.setTextureRect(sf::IntRect(0, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY));
		else //second ? sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 2) * 64 + 160, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY)) : sp.setTextureRect(sf::IntRect(128, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY));
			sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 4) * 32 + 128, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY));
	}
	else sp.setTextureRect(sf::IntRect(0, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY));

	sp.setTexture(character);
	sp.setPosition(camPosX, camPosY);
	window->draw(sp);
	
	window->display();
}

void MapView::load() {
	map.loadFromFile("data/city.png");
	character.loadFromFile("data/character.png");
	menu.loadFromFile("data/menu.png");
	bag.loadFromFile("data/bag.png");
	items.loadFromFile("data/items.png");
}

void MapView::drawImage(sf::Sprite& sp, const int xo, const int yo, const int sizex, const int sizey, const float posx, const float posy, const float scale) {
	sp.setTextureRect(sf::IntRect(xo, yo, sizex, sizey));
	sp.setPosition(posx, posy);
	sp.setScale(scale, scale);
	window->draw(sp);
}

MapView::MapView() {}
MapView::~MapView() {}