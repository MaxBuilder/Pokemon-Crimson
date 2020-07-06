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
	sp.setScale(5.f, 5.f);

	// Basic render :

	// Background
	sp.setTextureRect(sf::IntRect(0, 0, 256, 192));
	window->draw(sp);

	// Text render ....

	// Panel
	sp.setTextureRect(sf::IntRect(0, 326, 142, 126));
	sp.setPosition(540.f, 35.f);
	window->draw(sp);

	// Bag icon
	sp.setTextureRect(sf::IntRect(0 + (catId % 4) * 56, 194 + 58  * (catId > 3), 56, 58));
	sp.setPosition(100.f, 110.f);
	window->draw(sp);

	// Small icon + selector
	sp.setTextureRect(sf::IntRect(0 + catId * 12, 312, 12, 12));
	sp.setPosition(35.f + catId * 55.f, 450.f);
	window->draw(sp);
	sp.setTextureRect(sf::IntRect(150, 454, 14, 14));
	sp.setPosition(30.f + catId * 55.f, 445);
	window->draw(sp);



	window->display();
}

void MapView::renderMenu() {
	//window->clear(sf::Color(0, 255, 0, 255));
	render();

	// Reset de la view
	window->setView(window->getDefaultView());

	sf::Sprite sp;
	sp.setTexture(menu);
	sp.setScale(5.0, 5.0);
	int id = model->getGameState().menuId;
	
	// Menu texture 
	sp.setTextureRect(sf::IntRect(0, 0, 100, 180));
	sp.setPosition(760.f, 20.f);
	window->draw(sp);

	// Selector texture
	sp.setTextureRect(sf::IntRect(102, 2, 92, 26));
	sp.setPosition(780.f, 45 + id * 120.f);
	window->draw(sp);

	// Icons texture
	sp.setTextureRect(sf::IntRect( 102 + (id >= 4) * 24, 32 + (id % 4) * 24 , 24, 24));
	sp.setPosition(800.f, 50.f + id * 120.f);
	window->draw(sp);

	window->display();
}

void MapView::render(float x, float y, bool second) {
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

MapView::MapView() {}
MapView::~MapView() {}