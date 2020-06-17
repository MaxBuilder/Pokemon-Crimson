#include "Game.h"

void Game::launch() {
	create();
	while(run)
		loop();
	quit();
}

void Game::create() {
	model.init();
	view.initAll(model);
	controller.init(view, model);
}

void Game::loop() {
	int a = view.handleEvents();

	if (a == -1)
		run = false;
	else controller.update(a);
}

void Game::quit() {
	view.close();
}

Game::Game() { run = true; }

Game::~Game() {};

