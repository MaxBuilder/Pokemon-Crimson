#pragma once

#include <vector>
#include <json.hpp>
#include <algorithm>
#include <fstream>

using json = nlohmann::json;

struct Item {
	int id;
	int nb;
};

class Inventory
{
private:
	std::vector<Item> items;

public:
	// Initialise l'inventaire à partir de la sauvegarde de celui-ci
	void loadInventory();

	// Sauvegarde l'inventaire dans un fichier de sauvegarde
	void saveInventory();

	// Ajoute un item / une quantité à l'inventaire
	void addItem(const int id, const int quantity);

	// Set les itérateurs sur le numéro de catégorie passé en paramètre
	void setIterators(const int catId);

	// Getter d'un item
	Item& getItem(const int n);

	// Itérateurs
	std::vector<Item>::iterator itRef;
	std::vector<Item>::iterator itBegin;
	std::vector<Item>::iterator itEnd;

	// Constructeur et destructeur
	Inventory();
	~Inventory();

};

