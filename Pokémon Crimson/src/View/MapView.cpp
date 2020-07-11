#include "MapView.h"

void MapView::init(sf::RenderWindow& target, MainModel& m) {
	window = &target;
	model = &m;
	load();
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

void MapView::renderBag() {
	int catId = model->getGameState().invCatId;
	int itemId = model->getGameState().invItemId;
	int maxId = model->getGameState().invMaxItemId;
	Inventory& inv = model->getCharacter().getInventory();
	window->clear();
	sf::Sprite sp;
	sp.setTexture(bag);

	// Background + name + quantity
	drawImage(sp, 0, 326, 142, 126, 540.f, 35.f);
	int xPos = 0;
	if (catId == 3) xPos = 30;
	else if (catId == 7) xPos = 2000;
	int selecPos = 0;
	int ref = inv.itBegin - inv.itRef;
	if (itemId < 4 or maxId < 7) selecPos = 0;
	else if (itemId > maxId - 3) {
		drawText(model->itemData[ref + maxId - 7].name, 560, 15);
		drawText("x", 1105 + xPos, 15);
		drawText(std::to_string((inv.itBegin + maxId - 7)->nb), 1140 + xPos, 15);
		selecPos = maxId - 6;
	}
	else {
		drawText(model->itemData[ref + itemId - 4].name, 560, 15);
		drawText("x", 1105 + xPos, 15);
		drawText(std::to_string((inv.itBegin + itemId - 4)->nb), 1140 + xPos, 15);

		if (itemId - 3 > 0)
			selecPos = itemId - 3;
		else selecPos = maxId;
	}
	for (auto i = selecPos; i < selecPos + 8; i++) {
		if (i < maxId + 1 and i >= 0) {
			drawText(model->itemData[ref + i].name, 560, 95 + (i - selecPos) * 80);
			drawText("x", 1105 + xPos, 95 + (i - selecPos) * 80);
			drawText(std::to_string((inv.itBegin + i)->nb), 1140 + xPos, 95 + (i - selecPos) * 80);
		}
	}
	drawImage(sp, 0, 0, 256, 192);

	// Selector
	if (itemId < 4 or maxId < 7) selecPos = itemId * 80 + 75;
	else if (maxId - itemId < 3) selecPos = 315 + (3 - (maxId - itemId)) * 80;
	else selecPos = 315;
	drawImage(sp, 0, 454, 148, 17, 525, (float)selecPos);

	// Bag icon + small icon + selector + small text 
	drawImage(sp, 0 + (catId % 4) * 56, 194 + 58 * (catId > 3), 56, 58, 100.f, 110.f);
	drawImage(sp, 0 + catId * 12, 312, 12, 12, 35.f + catId * 55.f, 450.f);
	drawImage(sp, 150, 454, 14, 14, 30.f + catId * 55.f, 445);
	drawText(textMenu[catId], 40, 545);

	// Icons
	sp.setTexture(items);
	int originX = catId % 2 * 144 + (itemId % 6) * 24;
	int originY = (catId > 1) * 96 + (catId > 3) * 72 + (catId > 5) * 48 + itemId / 6 * 24;
	drawImage(sp, originX, originY, 24, 24, 30, 775);

	// Description 
	std::string toRender, description = model->itemData[ref + itemId].description;
	int line = 0;
	for (unsigned int i = 0; i < description.size(); i++) {
		if (description[i] != '|')
			toRender.push_back(description[i]);
		else {
			drawText(toRender, 200, 735 + line * 80, 3);
			toRender.clear();
			line++;
		}
	}

	// Render sub-menu 
	if (model->getGameState().invMenu) {
		sp.setTexture(bag);
		std::vector<std::string> catList;
		catList.push_back("ANNULER");
		if (catId != 3 and catId != 7)
			catList.push_back("JETER");
		if (catId == 7)
			catList.push_back("ENREG.");
		else catList.push_back("DONNER");
		if (catId == 1 or catId == 3 or catId == 4 or catId == 7)
			catList.push_back("UTILISER");

		if (catList.size() == 3) drawImage(sp, 144, 391, 69, 61, 925.f, 645.f);
		else drawImage(sp, 144, 312, 69, 77, 925.f, 565.f);

		for (unsigned int i = 0; i < catList.size(); i++)
			drawText(catList[i], 990, 855 - (i * 80));

		drawImage(sp, 134, 312, 8, 12, 950.f, 850.f - 80 * ((unsigned int)catList.size() - model->getGameState().invMenuId - 1));
	}

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
	if (model->getCharacter().moveCount > 0) {
		if (!model->getCharacter().sprint)
			second ? sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 2) * 64 + 32, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY)) : sp.setTextureRect(sf::IntRect(0, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY));
		else sp.setTextureRect(sf::IntRect((model->getCharacter().moveCount % 4) * 32 + 128, model->getCharacter().direction * 32, model->getCharacter().sizeX, model->getCharacter().sizeY));
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
	fonts[0].loadFromFile("data/fonts/black-gray.png");
	fonts[1].loadFromFile("data/fonts/black-lgray.png");
	fonts[2].loadFromFile("data/fonts/lblue-gray.png");
	fonts[3].loadFromFile("data/fonts/white-black.png");
	textMenu[0] = "      OBJETS";
    textMenu[1] = "   MEDICAMENTS";
    textMenu[2] = "       BALLS";
    textMenu[3] = "         CT";
    textMenu[4] = "       BERRY";
    textMenu[5] = "      LETTRE";
    textMenu[6] = " OBJETS COMBAT";
    textMenu[7] = "   OBJETS RARE";
}

void MapView::drawText(std::string line, int cursor, int y, int color, float ratio) {
	for (unsigned int i = 0; i < line.length(); i++) {
		sf::Sprite sp;
		sp.setTexture(fonts[color]);
		sp.setScale(ratio, ratio);

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
		sp.setTextureRect(sf::IntRect((id % 10) * 6, (int)(id / 10) * 10 - (line[i] == 'j'), 6, 10 + (line[i] == 'j')));
		sp.setPosition(((float)cursor + 5 * (line[i] == 39 or line[i] == '.' or line[i] == 44)) * ratio / 5, ((float)y + 10 * (line[i] == 'g' or line[i] == 'j' or line[i] == 'p' or line[i] == 'q' or line[i] == 'y' or line[i] == ',')) * ratio / 5);

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