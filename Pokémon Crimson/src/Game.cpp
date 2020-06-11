#include "Game.h"

void Game::gLaunch() {
	gCreate();
	while(run)
		gLoop();
	gQuits();
}

void Game::gCreate() {
	view.init();
	controller.init(view);
}

void Game::gLoop() {
	int a = view.update();

	if (a == -1)
		run = false;
	else controller.handleEvents(a);
}

void Game::gQuits() {
	view.close();
}

bool Game::gRunning() {
	return run;
}

Game::Game() { run = true; }

Game::~Game() {};

