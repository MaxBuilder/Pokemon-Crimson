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
	void renderWorld(float x = -1, float y = -1, bool second = false);
	// Render du menu
	void renderMenu();
	// Render de l'inventaire
	void renderBag();

	// TO DO : Animate transitions (parametre : x, y overide)


	// Fonctions auxiliaires

	// Render de texte
	void fdrawText(std::string line, int cursor, int y, int color = 0);

	// Render d'une image (allègement de la syntaxe)
	void drawImage(sf::Sprite& sp, const int xo, const int yo, const int sizex, const int sizey, const float posx = 0, const float posy = 0, const float scale = 5.f);


	// Constructeur et destructeur
	MapView();
	~MapView();
};

