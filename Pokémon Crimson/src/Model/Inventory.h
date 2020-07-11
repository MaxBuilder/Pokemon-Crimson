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

	// Fonction prenant en paramètre un item. Si l'item existe déja, la quantité est ajoutée, sinon l'item en lui même est ajouté à l'inventaire
	void addItem(const int id, const int quantity);

	// Set les itérateurs sur le numéro de catégorie passé en paramètre
	void setIterators(const int catId);

	// Getter d'une case du vector
	Item& getItem(const int n);

	// Itérateurs
	std::vector<Item>::iterator itRef;
	std::vector<Item>::iterator itBegin;
	std::vector<Item>::iterator itEnd;

	// Constructeur et destructeur
	Inventory();
	~Inventory();

};

