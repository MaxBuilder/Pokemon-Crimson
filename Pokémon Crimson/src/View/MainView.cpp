#include "MainView.h"

int MainView::handleEvents() {
	sf::Event event;
	window.pollEvent(event);

	// Quit 
	if (event.type == sf::Event::Closed)
		return -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return -1;

	// Shift pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			return 11;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			return 12;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			return 13;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			return 14;
	}

	// Shift not pressed
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			return 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			return 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			return 3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			return 4;
	}

	// Other
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		return 5;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return 6;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		return 7;

	// Default
	return 0;
}

void MainView::load() {
	textureHolder.load(texture::guiBag, "assets/textures/gui/bag.png");
	textureHolder.load(texture::guiCard, "assets/textures/gui/card.png");
	textureHolder.load(texture::guiMenu, "assets/textures/gui/menu.png");
	textureHolder.load(texture::guiPokedex, "assets/textures/gui/pokedex.png");
	textureHolder.load(texture::guiTeam, "assets/textures/gui/team.png");

	textureHolder.load(texture::spriteCharacter, "assets/textures/sprites/character.png");
	textureHolder.load(texture::spriteFootprints, "assets/textures/sprites/footprints.png");
	textureHolder.load(texture::spriteItem, "assets/textures/sprites/items.png");
	textureHolder.load(texture::spritePkmnBox, "assets/textures/sprites/pkmn-box.png");
	textureHolder.load(texture::spritePkmnFront, "assets/textures/sprites/pkmn-front-1.png");

	textureHolder.load(texture::tileCity, "assets/textures/tile/city.png"); // TO CHANGE

	textureHolder.load(texture::fontBlackGray, "assets/fonts/black-gray.png");
	textureHolder.load(texture::fontBlackLgray, "assets/fonts/black-lgray.png");
	textureHolder.load(texture::fontLblueGray, "assets/fonts/lblue-gray.png");
	textureHolder.load(texture::fontWhiteBlack, "assets/fonts/white-black.png");
	textureHolder.load(texture::fontWhiteGrey, "assets/fonts/white-grey.png");
}

void MainView::close() {
	window.close();
}

MainView::MainView(Model& m) : window(sf::VideoMode(1280, 960), "Pokemon Crimson", sf::Style::Close), mapView(window, m, textureHolder) {
	window.setFramerateLimit(120);
}
MainView::~MainView() {}