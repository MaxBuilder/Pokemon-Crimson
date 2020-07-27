#pragma once

#include "SFML/System.hpp"
#include "../View/MainView.h"

class Controller
{

private:
	MainView& view;
	Model& model;
	sf::Clock clock;
	int prevEvent;

public:
	
	// Initialisation du contr�leur
	void init();

	// Mise � jour du jeu :
	void update(int event);

	// Contr�leurs de la map :
	void mapUpdate(int event);

	// Sous fonctions du contr�leur
	void mapMovementUpdate(int movement);
	void mapMenuUpdate(int action);

	// Sous fonctions du contr�leur du menu
	void mapPokedexUpdate(int action);
	void mapTeamUpdate(int action);
	void mapBagUpdate(int action);

	// Contr�leurs du combat :
	//void combatUpdate();

	// Constructeur et destructeur
	Controller(MainView& v, Model& m);
	~Controller();
};

