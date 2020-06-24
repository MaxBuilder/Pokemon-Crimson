#include "MainView.h"

void MainView::initAll(MainModel& m) {
	window.create(sf::VideoMode(1280, 960), "Pokemon Crimson", sf::Style::Close);
	window.setFramerateLimit(60);

	mapView.init(window, m);
	// ...

}

int MainView::handleEvents() {
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

	// TO DO : A, E, X, ...

	// Default
	return 0;
}

void MainView::close() {
	std::cout << "Main view closing ... ";
	window.close();
	std::cout << "Done" << std::endl;
}

MainView::MainView() {}
MainView::~MainView() {}