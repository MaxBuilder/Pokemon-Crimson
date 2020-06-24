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

	// Mise à jour du modèle en fonction de l'event passé en paramètre)
	void update(int event);


	// Fonctions secondaires du contrôleur de la map
	void mapMovement(int movement);


	// Constructeur et destructeur
	Controller();
	~Controller();
};

