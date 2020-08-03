#include "Game.h"

void Game::launch() {
	create();
	while(run)
		loop();
	quit();
}

void Game::create() {
	controller.init();	// Chargement des donn�es
	view.load();		// Chargement des ressources graphiques
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

Game::Game() : model(), view(model), controller(view, model), run(true) {}
Game::~Game() {};

