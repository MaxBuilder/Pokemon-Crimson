#pragma once

#include <iostream>
#include "View/MainView.h"
#include "Controller/Controller.h"

class Game {

private:
	Model mModel;
	MainView mView;
	Controller mController;
	bool mRun;
	bool mHasFocus;

public:
	// Constructeur et destructeur
	Game();
	~Game();
	
	// Lancement du jeu
	void launch(); 

	// Création / initialisation du jeu
	void create();
	// Lance la boucle du jeu
	void loop();
	// Fermeture du jeu
	void quit();

};

