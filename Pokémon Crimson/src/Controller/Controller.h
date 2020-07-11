#pragma once

#include "SFML/System.hpp"
#include "../View/MainView.h"

class Controller
{

private:
	MainView * view;
	MainModel * model;
	sf::Clock clock;
	int prevEvent;

public:
	
	// Initialisation du constructeur (obtention de la view principale)
	void init(MainView& v, MainModel& m);

	// Mise à jour du jeu :
	void update(int event);

	// Contrôleurs de la map :
	void mapUpdate(int event);

	void mapMovementUpdate(int movement);
	void mapMenuUpdate(int action);
	void mapBagUpdate(int action);

	// Contrôleurs du combat :
	//void combatUpdate();

	// Constructeur et destructeur
	Controller();
	~Controller();
};

