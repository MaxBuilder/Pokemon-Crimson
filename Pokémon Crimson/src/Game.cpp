#include "Game.h"

void Game::launch() {
	create();
	while(mRun)
		loop();
	quit();
}

void Game::create() {
	mController.init();	// Chargement des données
	mView.load();		// Chargement des ressources graphiques
}

void Game::loop() {
	int event = mView.handleEvents();

	switch (event) {
	case -1:
		mRun = false;
		break;
	case 10:
		mHasFocus = false;
		break;
	case 11:
		mHasFocus = true;
		break;
	}
	
	if(mHasFocus)
		mController.update(event);
}

void Game::quit() {
	mView.close();
	std::cout << "Normal closing " << std::endl;
}

Game::Game() : mModel(), mView(mModel), mController(mView, mModel), mRun(true), mHasFocus(true) {}
Game::~Game() {};

