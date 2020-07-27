#pragma once
#include "MapView.h"

class MainView
{

private:
	sf::RenderWindow window;

public:
	MapView mapView;
	// CombatView combatView;
	// etc ...

	// Fermeture de la view principale
	void close();

	// Récuperation des évènements
	int handleEvents();


	// Constructeur et destructeur
	MainView(Model& m);
	~MainView();
};

