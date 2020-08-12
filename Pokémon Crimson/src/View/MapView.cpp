#include "MapView.h"

// Render functions

void MapView::renderMenu() {
	renderWorld();

	// Reset de la view
	window.setView(window.getDefaultView());

	int id = model.getGameState().menuId;
	sf::Sprite sp;
	sp.setTexture(textureHolder.get(texture::guiMenu));

	// Menu, selector, icons
	drawImage(sp, 0, 0, 100, 180, 760.f, 20.f);
	drawImage(sp, 102, 2, 92, 26, 780.f, 45 + id * 120.f);
	drawImage(sp, 102 + (id >= 4) * 24, 32 + (id % 4) * 24, 24, 24, 800.f, 50.f + id * 120.f);

	window.display();
}

// TO DO : Animations + sub menu select
void MapView::renderTeam() {
	window.clear();
	PkmnTeam& pkmnTeam = model.getCharacter().getPkmnTeam();
	sf::Sprite sp;
	sf::Sprite spb;

	// Background
	sp.setTexture(textureHolder.get(texture::guiTeam));
	spb.setTexture(textureHolder.get(texture::spritePkmnBox));
	drawImage(sp, 0, 0, 256, 192);

	// Test 
	pkmnTeam.getPkmn(2).stats.at(0) = 0;
	pkmnTeam.getPkmn(3).stats.at(0) = 0;
	pkmnTeam.getPkmn(4).stats.at(0) = 0;
	pkmnTeam.getPkmn(5).stats.at(0) = 0;
	pkmnTeam.getPkmn(0).gender = 2;
	pkmnTeam.getPkmn(1).gender = 2;
	pkmnTeam.getPkmn(2).gender = 2;

	// Render selected
	int pkmnId = model.getGameState().teamId;
	if (pkmnId == 0) {
		if (!pkmnTeam.getPkmn(0).isKo()) drawImage(sp, 0, 237, 128, 49);
		else drawImage(sp, 129, 282, 128, 49);
	}
	else if (pkmnId == 1 and pkmnTeam.size() > 1) {
		if (!pkmnTeam.getPkmn(1).isKo()) drawImage(sp, 0, 286, 128, 49, 640, 40);
		else drawImage(sp, 128, 331, 128, 49, 640, 40);
	}
	else if (pkmnId == 2 and pkmnTeam.size() > 2) {
		if (!pkmnTeam.getPkmn(2).isKo()) drawImage(sp, 0, 286, 128, 49, 0, 240);
		else drawImage(sp, 128, 331, 128, 49, 0, 240);
	}
	else if (pkmnId == 3 and pkmnTeam.size() > 3) {
		if (!pkmnTeam.getPkmn(3).isKo()) drawImage(sp, 0, 286, 128, 49, 640, 280);
		else drawImage(sp, 128, 331, 128, 49, 640, 280);
	}
	else if (pkmnId == 4 and pkmnTeam.size() > 4) {
		if (!pkmnTeam.getPkmn(4).isKo()) drawImage(sp, 0, 286, 128, 49, 0, 480);
		else drawImage(sp, 128, 331, 128, 49, 0, 480);
	}
	else if (pkmnId == 5 and pkmnTeam.size() > 5) {
		if (!pkmnTeam.getPkmn(5).isKo()) drawImage(sp, 0, 286, 128, 49, 640, 520);
		else drawImage(sp, 128, 331, 128, 49, 640, 520);
	}
	else if (pkmnId == pkmnTeam.size()) drawImage(sp, 0, 336, 58, 26, 990, 815);             


	// Render infos
	if (pkmnTeam.getPkmn(0).isKo() and pkmnId != 0) drawImage(sp, 129, 192, 126, 45, 5, 15);
	drawText(pkmnTeam.getPkmn(0).name, 240, 55, 4);
	drawNum(pkmnTeam.getPkmn(0).level, 105, 175);
	if (pkmnTeam.getPkmn(0).gender == 1) drawImage(sp, 59, 352, 6, 10, 560, 55);
	else if (pkmnTeam.getPkmn(0).gender == 2) drawImage(sp, 66, 352, 6, 10, 560, 55);
	drawImage(spb, (pkmnTeam.getPkmn(0).id - 1) % 25 * 32, (pkmnTeam.getPkmn(0).id - 1) / 25 * 32, 32, 32, 64, 16);
	drawNum(pkmnTeam.getPkmn(0).getHp(), 300 + (pkmnTeam.getPkmn(0).getHp() < 100) * 40 + (pkmnTeam.getPkmn(0).getHp() < 10) * 40, 175);
	drawNum(pkmnTeam.getPkmn(0).getMaxHp(), 460, 175);

	if (pkmnTeam.size() > 1) {
		if (pkmnId != 1) {
			if (pkmnTeam.getPkmn(1).isKo()) drawImage(sp, 129, 237, 126, 45, 645, 55);
			else drawImage(sp, 0, 192, 126, 45, 645, 55);
		}
		drawText(pkmnTeam.getPkmn(1).name, 880, 95, 4);
		drawNum(pkmnTeam.getPkmn(1).level, 745, 215);
		if (pkmnTeam.getPkmn(1).gender == 1) drawImage(sp, 59, 352, 6, 10, 1200, 95);
		else if (pkmnTeam.getPkmn(1).gender == 2) drawImage(sp, 66, 352, 6, 10, 1200, 95);
		drawImage(spb, (pkmnTeam.getPkmn(1).id - 1) % 25 * 32, (pkmnTeam.getPkmn(1).id - 1) / 25 * 32, 32, 32, 710, 65);
		drawNum(pkmnTeam.getPkmn(1).getHp(), 940 + (pkmnTeam.getPkmn(1).getHp() < 100) * 40 + (pkmnTeam.getPkmn(1).getHp() < 10) * 40, 215);
		drawNum(pkmnTeam.getPkmn(1).getMaxHp(), 1100, 215);
	}
	if (pkmnTeam.size() > 2) {
		if (pkmnId != 2) {
			if (pkmnTeam.getPkmn(2).isKo()) drawImage(sp, 129, 237, 126, 45, 5, 255);
			else drawImage(sp, 0, 192, 126, 45, 5, 255);
		}
		drawText(pkmnTeam.getPkmn(2).name, 240, 295, 4);
		drawNum(pkmnTeam.getPkmn(2).level, 105, 415);
		if (pkmnTeam.getPkmn(2).gender == 1) drawImage(sp, 59, 352, 6, 10, 560, 295);
		else if (pkmnTeam.getPkmn(2).gender == 2) drawImage(sp, 66, 352, 6, 10, 560, 295);
		drawImage(spb, (pkmnTeam.getPkmn(2).id - 1) % 25 * 32, (pkmnTeam.getPkmn(2).id - 1) / 25 * 32, 32, 32, 64, 265);
		drawNum(pkmnTeam.getPkmn(2).getHp(), 300 + (pkmnTeam.getPkmn(2).getHp() < 100) * 40 + (pkmnTeam.getPkmn(2).getHp() < 10) * 40, 415);
		drawNum(pkmnTeam.getPkmn(2).getMaxHp(), 460, 415);
	}
	if (pkmnTeam.size() > 3) {
		if (pkmnId != 3) {
			if (pkmnTeam.getPkmn(3).isKo()) drawImage(sp, 129, 237, 126, 45, 645, 295);
			else drawImage(sp, 0, 192, 126, 45, 645, 295);
		}
		drawText(pkmnTeam.getPkmn(3).name, 880, 335, 4);
		drawNum(pkmnTeam.getPkmn(3).level, 745, 455);
		if (pkmnTeam.getPkmn(3).gender == 1) drawImage(sp, 59, 352, 6, 10, 1200, 335);
		else if (pkmnTeam.getPkmn(3).gender == 2) drawImage(sp, 66, 352, 6, 10, 1200, 335);
		drawImage(spb, (pkmnTeam.getPkmn(3).id - 1) % 25 * 32, (pkmnTeam.getPkmn(3).id - 1) / 25 * 32, 32, 32, 710, 300);
		drawNum(pkmnTeam.getPkmn(3).getHp(), 940 + (pkmnTeam.getPkmn(3).getHp() < 100) * 40 + (pkmnTeam.getPkmn(3).getHp() < 10) * 40, 455);
		drawNum(pkmnTeam.getPkmn(3).getMaxHp(), 1100, 455);
	}
	if (pkmnTeam.size() > 4) {
		if (pkmnId != 4) {
			if (pkmnTeam.getPkmn(4).isKo()) drawImage(sp, 129, 237, 126, 45, 5, 495);
			else drawImage(sp, 0, 192, 126, 45, 5, 495);
		}
		drawText(pkmnTeam.getPkmn(4).name, 240, 535, 4);
		drawNum(pkmnTeam.getPkmn(4).level, 105, 655);
		if (pkmnTeam.getPkmn(4).gender == 1) drawImage(sp, 59, 352, 6, 10, 560, 535);
		else if (pkmnTeam.getPkmn(4).gender == 2) drawImage(sp, 66, 352, 6, 10, 560, 535);
		drawImage(spb, (pkmnTeam.getPkmn(4).id - 1) % 25 * 32, (pkmnTeam.getPkmn(4).id - 1) / 25 * 32, 32, 32, 64, 505);
		drawNum(pkmnTeam.getPkmn(4).getHp(), 300 + (pkmnTeam.getPkmn(4).getHp() < 100) * 40 + (pkmnTeam.getPkmn(4).getHp() < 10) * 40, 655);
		drawNum(pkmnTeam.getPkmn(4).getMaxHp(), 460, 655);
	}
	if (pkmnTeam.size() > 5) {
		if (pkmnId != 5) {
			if (pkmnTeam.getPkmn(5).isKo()) drawImage(sp, 129, 237, 126, 45, 645, 535);
			else drawImage(sp, 0, 192, 126, 45, 645, 535);
		}
		drawText(pkmnTeam.getPkmn(5).name, 880, 575, 4);
		drawNum(pkmnTeam.getPkmn(5).level, 745, 695);
		if (pkmnTeam.getPkmn(5).gender == 1) drawImage(sp, 59, 352, 6, 10, 1200, 575);
		else if (pkmnTeam.getPkmn(5).gender == 2) drawImage(sp, 66, 352, 6, 10, 1200, 575);
		drawImage(spb, (pkmnTeam.getPkmn(5).id - 1) % 25 * 32, (pkmnTeam.getPkmn(5).id - 1) / 25 * 32, 32, 32, 710, 535);
		drawNum(pkmnTeam.getPkmn(5).getHp(), 940 + (pkmnTeam.getPkmn(5).getHp() < 100) * 40 + (pkmnTeam.getPkmn(5).getHp() < 10) * 40, 695);
		drawNum(pkmnTeam.getPkmn(5).getMaxHp(), 1100, 695);
	}
	
	window.display();
}

// TO DO : Animations et cri + sons + lambda
void MapView::renderPokedex() {
	window.clear();
	sf::Sprite sp;

	// Background
	sp.setTexture(textureHolder.get(texture::guiPokedex));
	drawImage(sp, 0, 0, 256, 192);
	int id = model.getGameState().pkdxId + 1;
	PkmnData pkmn = model.pkmnData[id];
	
	// Informations générales
	drawText(pkmn.name, 785, 135, 1);
	drawText(pkmn.category, 680, 225, 1);
	drawText(pkmn.height, 935, 455);
	drawText(pkmn.weight, 935, 535);
	drawImage(sp, ((pkmn.type1 - 1) % 4) * 48, 192 + ((pkmn.type1 - 1) / 4) * 16, 48, 16, 730, 320);
	if(pkmn.type2 != 0) drawImage(sp, ((pkmn.type2 - 1) % 4) * 48, 192 + ((pkmn.type2 -1 )/ 4) * 16, 48, 16, 980, 320);

	// Sprite + footprints
	sp.setTexture(textureHolder.get(texture::spritePkmnFront));
	drawImage(sp, ((id - 1) % 28) * 80, ((id - 1) / 28) * 80, 80, 80, 40, 160);
	sp.setTexture(textureHolder.get(texture::spriteFootprints));
	drawImage(sp, ((id - 1) % 31) * 16, ((id - 1) / 31) * 16, 16, 16, 560, 400);

	// id
	int a = 0, b = 0, c = 0;
	if (id > 99) a = id / 100;
	drawText(std::to_string(a), 650 + (a == 1) * 10, 135, 1);
	if (id - a * 100 > 9) b = (id - a * 100) / 10;
	drawText(std::to_string(b), 685 + (b == 1) * 5, 135, 1);
	c = id - a * 100 - b * 10;
	drawText(std::to_string(c), 720, 135, 1);

	// Pokedex entry
	std::string desc = pkmn.pokedex_entry, curr = {}, render = {};
	int line = 0;
	for (unsigned int i = 0; i < desc.size(); i++) {
		if (desc.at(i) != ' ')
			curr.push_back(desc.at(i));
		else {
			if (render.size() + curr.size() > 35) {
				drawText(render, 145, 695 + line * 80);
				render.clear();
				render.append(curr + " ");
				line++;
			}
			else {
				render.append(curr);
				render.push_back(' ');
			}
			curr.clear();
		}
		drawText(render + curr, 145, 695 + line * 80);
	}

	window.display();
}

// TO DO : Finir affichage
void MapView::renderCard() {
	Character& chara = model.getCharacter();
	window.clear();
	sf::Sprite sp;
	sp.setTexture(textureHolder.get(texture::guiCard));
	drawImage(sp, 0, 352, 256, 192, 0, 0);
	drawImage(sp, (chara.stars % 3) * 240, (chara.stars > 2) * 176, 240, 176, 40, 40);

	// Render du text
	
	window.display();
}

// TO DO : Animate transitions(parametre : x, y overide) + choix selection sous menu
void MapView::renderBag() {
	int catId = model.getGameState().invCatId;
	int itemId = model.getGameState().invItemId;
	int maxId = model.getGameState().invMaxItemId;
	Inventory& inv = model.getCharacter().getInventory();
	window.clear();
	sf::Sprite sp;
	sp.setTexture(textureHolder.get(texture::guiBag));

	// Background + name + quantity
	drawImage(sp, 0, 326, 142, 126, 540.f, 35.f);
	int xPos = 0;
	if (catId == 3) xPos = 30;
	else if (catId == 7) xPos = 2000;
	int selecPos = 0;
	int ref = inv.itBegin - inv.itRef;
	if (itemId < 4 or maxId < 7) selecPos = 0;
	else if (itemId > maxId - 3) {
		drawText(model.itemData[ref + maxId - 7].name, 560, 15);
		drawText("x", 1105 + xPos, 15);
		drawText(std::to_string((inv.itBegin + maxId - 7)->nb), 1140 + xPos, 15);
		selecPos = maxId - 6;
	}
	else {
		drawText(model.itemData[ref + itemId - 4].name, 560, 15);
		drawText("x", 1105 + xPos, 15);
		drawText(std::to_string((inv.itBegin + itemId - 4)->nb), 1140 + xPos, 15);

		if (itemId - 3 > 0)
			selecPos = itemId - 3;
		else selecPos = maxId;
	}
	for (auto i = selecPos; i < selecPos + 8; i++) {
		if (i < maxId + 1 and i >= 0) {
			drawText(model.itemData[ref + i].name, 560, 95 + (i - selecPos) * 80);
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
	sp.setTexture(textureHolder.get(texture::spriteItem));
	int originX = catId % 2 * 144 + (itemId % 6) * 24;
	int originY = (catId > 1) * 96 + (catId > 3) * 72 + (catId > 5) * 48 + itemId / 6 * 24;
	drawImage(sp, originX, originY, 24, 24, 30, 775);

	// Description 
	std::string toRender, description = model.itemData[ref + itemId].description;
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
	if (model.getGameState().invMenu) {
		sp.setTexture(textureHolder.get(texture::guiBag));
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

		drawImage(sp, 134, 312, 8, 12, 950.f, 850.f - 80 * ((unsigned int)catList.size() - model.getGameState().invMenuId - 1));
	}

	window.display();
}

void MapView::renderWorld(float x, float y, bool second) {
	// Camera coord selection
	float camPosX, camPosY;
	x == -1 ? camPosX = model.getCharacter().posX * 16.f + 16 : camPosX = x;
	y == -1 ? camPosY = model.getCharacter().posY * 16.f + 16 : camPosY = y;

	// Camera
	view.setCenter(camPosX+16, camPosY+16);
	view.setSize(256, 192);
	window.setView(view);

	window.clear();
	
	// Map
	sf::Sprite sp;
	sp.setTexture(textureHolder.get(texture::tileCity));
	window.draw(sp); 

	// Character
	if (model.getCharacter().moveCount > 0) {
		if (!model.getCharacter().sprint)
			second ? sp.setTextureRect(sf::IntRect((model.getCharacter().moveCount % 2) * 64 + 32, model.getCharacter().direction * 32, model.getCharacter().sizeX, model.getCharacter().sizeY)) : sp.setTextureRect(sf::IntRect(0, model.getCharacter().direction * 32, model.getCharacter().sizeX, model.getCharacter().sizeY));
		else sp.setTextureRect(sf::IntRect((model.getCharacter().moveCount % 4) * 32 + 128, model.getCharacter().direction * 32, model.getCharacter().sizeX, model.getCharacter().sizeY));
	}
	else sp.setTextureRect(sf::IntRect(0, model.getCharacter().direction * 32, model.getCharacter().sizeX, model.getCharacter().sizeY));
	sp.setTexture(textureHolder.get(texture::spriteCharacter));
	sp.setPosition(camPosX, camPosY);
	window.draw(sp);
	
	window.display();
}

// Drawing functions :

void MapView::drawNum(int num, int cursor, int y) {
	sf::Sprite sp;
	sp.setTexture(textureHolder.get(texture::guiTeam));
	sp.setScale(5.f, 5.f);

	int a = 0, b = 0, c = 0, d = 0;
	a = num / 1000 % 10;
	if (a > 0) {
		drawImage(sp, 9 + a * 8 + a, 372, 8, 7, (float)cursor, (float)y);
		cursor += 40;
	}
	b = num / 100 % 10;
	if (b > 0 or a != 0) {
		drawImage(sp, 9 + b * 8 + b, 372, 8, 7, (float)cursor, (float)y);
		cursor += 40;
	}
	c = num / 10 % 10; 
	if (c > 0 or b != 0 or a != 0) {
		drawImage(sp, 9 + c * 8 + c, 372, 8, 7, (float)cursor, (float)y);
		cursor += 40;
	}
	d = num % 10;
	if (d >= 0 or c != 0 or b != 0 or a != 0) {
		drawImage(sp, 9 + d * 8 + d, 372, 8 , 7, (float)cursor, (float)y);
		cursor += 40;
	}
}

void MapView::drawText(std::string line, int cursor, int y, int color, float ratio) {
	sf::Sprite sp;
	if (color == 0) sp.setTexture(textureHolder.get(texture::fontBlackGray));
	else if(color == 1) sp.setTexture(textureHolder.get(texture::fontBlackLgray));
	else if(color == 2) sp.setTexture(textureHolder.get(texture::fontLblueGray));
	else if(color == 3) sp.setTexture(textureHolder.get(texture::fontWhiteBlack));
	else if(color == 4) sp.setTexture(textureHolder.get(texture::fontWhiteGrey));
	sp.setScale(ratio, ratio);

	for (unsigned int i = 0; i < line.length(); i++) {
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

		window.draw(sp);
	}
}

void MapView::drawImage(sf::Sprite& sp, const int xo, const int yo, const int sizex, const int sizey, const float posx, const float posy, const float scale) {
	sp.setTextureRect(sf::IntRect(xo, yo, sizex, sizey));
	sp.setPosition(posx, posy);
	sp.setScale(scale, scale);
	window.draw(sp);
}

MapView::MapView(sf::RenderWindow& w, Model& m, ResourceHolder<sf::Texture, texture::id>& t) : model(m), window(w), textureHolder(t) {
	// TO REDO
	textMenu.at(0) = "      OBJETS";
	textMenu.at(1) = "   MEDICAMENTS";
	textMenu.at(2) = "       BALLS";
	textMenu.at(3) = "         CT";
	textMenu.at(4) = "       BERRY";
	textMenu.at(5) = "      LETTRE";
	textMenu.at(6) = " OBJETS COMBAT";
	textMenu.at(7) = "   OBJETS RARE";
}
MapView::~MapView() {}