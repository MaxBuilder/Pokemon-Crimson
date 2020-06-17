#pragma once
#include "View/MainView.h"
#include "Controller/Controller.h"
#include "Model/MainModel.h"

class Game {

private:
	MainModel model;
	MainView view;
	// MainController controller;
	bool run;

	// Temporaire
	Controller controller;

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

