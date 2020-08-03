#pragma once

#include"../util/ResourceHolder.h"
#include "MapView.h"
#include "Texture.h"
#include <iostream>

class MainView
{

private:
	ResourceHolder<sf::Texture, texture::id> textureHolder;
	sf::RenderWindow window;

public:
	MapView mapView;
	// CombatView combatView;

	// Chargement de toutes les ressources graphiques
	void load();

	// Fermeture de la view principale
	void close();

	// Récuperation des évenements
	int handleEvents();


	// Constructeur et destructeur
	MainView(Model& m);
	~MainView();
};

