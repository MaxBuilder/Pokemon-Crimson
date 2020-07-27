#include "Game.h"

void Game::launch() {
	create();
	while(run)
		loop();
	quit();
}

void Game::create() {
	controller.init(); // Chargement des données, ...
	run = true;
}

void Game::loop() {
	int a = view.handleEvents();

	if (a == -1)
		run = false;
	else controller.update(a);
}

void Game::quit() {
	view.close();
	std::cout << "Normal closing " << std::endl;
}

Game::Game() : model(), view(model), controller(view, model) {}
Game::~Game() {};

