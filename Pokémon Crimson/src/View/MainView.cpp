#include "MainView.h"

void MainView::initAll(MainModel& m) {
	window.create(sf::VideoMode(1280, 960), "Pokemon Crimson", sf::Style::Close);
	window.setFramerateLimit(60);

	mapView.init(window, m);
	// ...

}

int MainView::handleEvents() {
	window.pollEvent(event);

	if (event.type == sf::Event::Closed)
		return -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		return 1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		return 2;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		return 3;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return 4;
	else return 0;
}

void MainView::close() {
	std::cout << "Main view closing ... ";
	window.close();
	std::cout << "Done" << std::endl;
}

MainView::MainView() {}
MainView::~MainView() {}