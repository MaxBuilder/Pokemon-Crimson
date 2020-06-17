#pragma once
#include "MapView.h"

class MainView
{

private:
	sf::RenderWindow window;
	sf::Event event;

public:
	MapView mapView;
	// CombatView combatView;
	// etc ...

	// Initialisation des views secondaires
	void initAll(MainModel& m);

	// Fermeture de la view principale
	void close();

	// R�cup�ration des �v�nements
	int handleEvents();


	// Constructeur et destructeur
	MainView();
	~MainView();
};

