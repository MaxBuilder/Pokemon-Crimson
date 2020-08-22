#pragma once

#include "SFML/System.hpp"
#include "../View/MainView.h"
#include <iostream>

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

	// Chargement des sons
	void loadSound();

	// Mise � jour du jeu :
	void update(int event);


	// Contr�leurs de la map :
	void mapUpdate(int event);
	void battleUpdate(int event);

	// Sous fonctions du contr�leur de la map
	void mapMovementUpdate(int movement);
	void mapMenuUpdate(int action);

	// Sous fonctions du contr�leur du menu
	void mapPokedexUpdate(int action); 
	void mapTeamUpdate(int action); // TO DO
	void mapBagUpdate(int action);
	void mapCardUpdate(int action);
	void mapSaveUpdate(int action); // TO DO
	void mapOptionsUpdate(int action); // TO DO


	// Contr�leurs du combat :
	//void combatUpdate();

	// Constructeur et destructeur
	Controller(MainView& v, Model& m);
	~Controller();
};

