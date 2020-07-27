#pragma once

#include <iostream>
#include "View/MainView.h"
#include "Controller/Controller.h"

class Game {

private:
	Model model;
	MainView view;
	Controller controller;
	bool run;

public:
	// Constructeur et destructeur
	Game();
	~Game();
	
	// Lancement du jeu
	void launch(); 

	// Cr�ation / initialisation du jeu
	void create();
	// Lance la boucle du jeu
	void loop();
	// Fermeture du jeu
	void quit();

};

