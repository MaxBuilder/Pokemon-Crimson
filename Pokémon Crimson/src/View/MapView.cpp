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
	fonts[0].loadFromFile("data/fonts/black-grey.png");
	fonts[1].loadFromFile("data/fonts/black-lgrey.png");
	fonts[2].loadFromFile("data/fonts/lblue-grey.png");
	fonts[3].loadFromFile("data/fonts/white-black.png");
}

//TO DO : Ajout du ratio en surcharge + remplacer valeurs en int
void MapView::drawText(std::string line, int cursor, int y, int color) {
	for (unsigned int i = 0; i < line.length(); i++) {
		sf::Sprite sp;
		sp.setTexture(fonts[color]);
		sp.setScale(5.f, 5.f);

		int id;
		if (line[i] > 64 and line[i] < 91) id = line[i] - 65;
		else if (line[i] > 96 and line[i] < 123) id = line[i] - 67;
		else if (line[i] > 47 and line[i] < 58) id = line[i] + 12;
		else if (line[i] == 39) id = 70;
		else if (line[i] == 46) id = 71;
		else if (line[i] == 44) id = 72;
		else if (line[i] == 33) id = 73;
		else if (line[i] == 63) id = 74;
		else if (line[i] == 43) id = 75;
		else if (line[i] == 45) id = 76;
		else if (line[i] == 58) id = 77;
		else if (line[i] == -61) continue;
		else if (line[i] == -87) id = 56;
		else if (line[i] == -88) id = 57;
		else if (line[i] == -86) id = 58;
		else if (line[i] == -96) id = 59;
		else { // Espace
			cursor += 20;
			continue;
		}
		sp.setTextureRect(sf::IntRect((id % 10) * 6, (int)(id / 10) * 10, 6, 10));
		sp.setPosition((float)cursor, (float)y + 10 * (line[i] == 'g' or line[i] == 'j' or line[i] == 'p' or line[i] == 'q' or line[i] == 'y'));

		if (line[i] == 'i' or line[i] == '!') cursor += 10;
		else if (line[i] == 'l' or line[i] == 39) cursor += 15;
		else if (line[i] == 'j' or line[i] == 'I') cursor += 20;
		else if (line[i] == 'f' or line[i] == 't' or line[i] == '1') cursor += 25;
		else cursor += 30;

		window->draw(sp);
	}
}

void MapView::drawImage(sf::Sprite& sp, const int xo, const int yo, const int sizex, const int sizey, const float posx, const float posy, const float scale) {
	sp.setTextureRect(sf::IntRect(xo, yo, sizex, sizey));
	sp.setPosition(posx, posy);
	sp.setScale(scale, scale);
	window->draw(sp);
}

MapView::MapView() {}
MapView::~MapView() {}