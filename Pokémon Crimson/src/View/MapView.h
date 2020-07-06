#pragma once
#include <SFML/graphics.hpp>
#include "../Model/MainModel.h"
#include <iostream>

class MapView
{

private:
	sf::RenderWindow* window;
	MainModel* model;

	sf::View view;
	sf::Texture map;
	sf::Texture character;
	sf::Texture menu;
	sf::Texture bag;
	sf::Texture items;


public:
	// Initalisation de la view secondaire 
	void init(sf::RenderWindow & target, MainModel& m);

	// Chargement de toutes les textures 
	void load();

	// Render de la map (classique)
	void render(float x = -1, float y = -1, bool second = false);

	// Render du menu
	void renderMenu();

	// Render de l'inventaire
	void renderBag();


	// Constructeur et destructeur
	MapView();
	~MapView();
};

