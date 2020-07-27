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

	// R�cuperation des �v�nements
	int handleEvents();


	// Constructeur et destructeur
	MainView(Model& m);
	~MainView();
};

