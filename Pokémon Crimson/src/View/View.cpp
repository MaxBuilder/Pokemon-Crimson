#include "View.h"

void View::init() {
	window.create(sf::VideoMode(1280, 960), "Pokemon Crimson", sf::Style::Close);
	load();
}

int View::update() {
	window.pollEvent(event);

	if (event.type == sf::Event::Closed)
		return -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return 1;
	else return 0;
}

void View::close() {
	window.close();
}

void View::render(bool mode) {
	window.clear();
	
	if (mode) 	
		window.draw(shape);

	window.display();
}

void View::load() {
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Red);
}