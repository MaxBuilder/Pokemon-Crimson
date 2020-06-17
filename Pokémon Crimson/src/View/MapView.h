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


	//void loadTexture(std::string path);

public:
	
	// Initalisation de la view secondaire 
	void init(sf::RenderWindow & target, MainModel& m);

	// Chargement de toutes les textures 
	void load();

	// Render de la fenêtre 
	void render(float x = -1, float y = -1);


	// Constructeur et destructeur
	MapView();
	~MapView();
};

