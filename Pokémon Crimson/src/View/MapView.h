#pragma once

#include <SFML/graphics.hpp>
#include "../model/Model.h"
#include"../util/ResourceHolder.h"
#include "Texture.h"

class MapView
{

private:
	sf::RenderWindow& window;
	Model& model;
	ResourceHolder<sf::Texture, texture::id>& textureHolder;

	sf::View view;

	//  TO REDO
	std::array<std::string, 8> textMenu;


public:
	// Render de la map
	void renderWorld(float x = -1, float y = -1, bool second = false);
	// Render du menu
	void renderMenu();
	// Render de l'équipe
	void renderTeam();
	// Render de l'inventaire 
	void renderBag();
	// Render de la carte de dresseur
	void renderCard();
	// Render du pokédex
	void renderPokedex();

private:
	// Fonction de draw :

	// Draw de texte
	void drawText(std::string line, int cursor, int y, int color = 0, float ratio = 5.f);
	// Draw d'une image
	void drawImage(sf::Sprite& sp, const int xo, const int yo, const int sizex, const int sizey, const float posx = 0, const float posy = 0, const float scale = 5.f);
	// Draw de chiffres
	void drawNum(int num, int cursor, int y);

public:

	// Constructeur et destructeur
	MapView(sf::RenderWindow& w, Model& m, ResourceHolder<sf::Texture, texture::id>& t);
	~MapView();
};

