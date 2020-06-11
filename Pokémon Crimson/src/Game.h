#pragma once
#include "View/View.h"
#include "Controller/Controller.h"

class Game {

private:
	// MainModel model;
	// MainView view;
	// MainController controller;
	bool run;

	// Temporaire
	View view;
	Controller controller;

public:
	// Constructeur et destructeur
	Game();
	~Game();
	
	// Lancement du jeu
	void gLaunch(); 

	// Cr�ation / initialisation du jeu
	void gCreate();
	// Lance la boucle du jeu
	void gLoop();
	// Fermeture du jeu
	void gQuits();
	// Retourne l'�tat de fonctionnement du jeu
	bool gRunning();

};

