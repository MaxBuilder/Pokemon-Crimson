#pragma once
#include <SFML/graphics.hpp>
#include "../Model/Model.h"
#include <iostream>

class MapView
{

private:
	sf::RenderWindow& window;
	Model& model;

	sf::View view;
	sf::Texture map;
	sf::Texture character;
	sf::Texture menu;
	sf::Texture bag;
	sf::Texture items;
	sf::Texture card;
	sf::Texture pokedex;
	sf::Texture pkmnSprite;
	sf::Texture footprints;
	sf::Texture fonts[4];
	std::string textMenu[8];


public:
	// Chargement de toutes les textures 
	void load();

	// Render de la map
	void renderWorld(float x = -1, float y = -1, bool second = false);
	// Render du menu
	void renderMenu();
	// Render de l'inventaire 
	void renderBag();
	// Render de la carte de dresseur
	void renderCard();
	// Render du pokédex
	void renderPokedex();


	// Fonctions auxiliaires

	// Render de texte
	void drawText(std::string line, int cursor, int y, int color = 0, float ratio = 5.f);

	// Render d'une image (allègement de la syntaxe)
	void drawImage(sf::Sprite& sp, const int xo, const int yo, const int sizex, const int sizey, const float posx = 0, const float posy = 0, const float scale = 5.f);


	// Constructeur et destructeur
	MapView(sf::RenderWindow& w, Model& m);
	~MapView();
};

