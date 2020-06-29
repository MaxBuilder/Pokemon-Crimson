#pragma once
#include <vector>

struct Item {
	int id;
	int nb;
	int assets;
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
	void addItem(Item item, int quantity);

	// Constructeur et destructeur
	Inventory();
	~Inventory();

};

