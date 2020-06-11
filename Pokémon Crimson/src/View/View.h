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

	// R�cup�ration des �v�nements et retour cod�
	int update();


	// Fonctions sp�cifiques aux vues secondaires :

	// Chargement de toutes les textures de la view
	void load();

	// Render de la fen�tre
	void render(bool mode);

	// Fermeture de la view
	void close();

};

