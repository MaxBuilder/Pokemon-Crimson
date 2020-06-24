#pragma once
#include "SFML/System.hpp"
#include "../View/MainView.h"

class Controller
{

private:
	MainView * view;
	MainModel * model;
	sf::Clock clock;

public:
	
	// Initialisation du constructeur (obtention de la view principale)
	void init(MainView& v, MainModel& m);

	// Mise � jour du mod�le en fonction de l'event pass� en param�tre)
	void update(int event);

	void mapUpdate(int event);

	// Fonctions secondaires du contr�leur de la map
	void mapMovement(int movement);
	void mapMenu(int action);


	// Constructeur et destructeur
	Controller();
	~Controller();
};

