#pragma once
#include <SFML/graphics.hpp>

class View
{

private:
	sf::RenderWindow window;
	sf::Event event;
	sf::CircleShape shape;

	// Textures etc

public:
	// Initalisation de la view
	void init();

	// Récupération des évènements et retour codé
	int update();


	// Fonctions spécifiques aux vues secondaires :

	// Chargement de toutes les textures de la view
	void load();

	// Render de la fenêtre
	void render(bool mode);

	// Fermeture de la view
	void close();

};

