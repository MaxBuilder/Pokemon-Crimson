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
	// Initialise l'inventaire � partir de la sauvegarde de celui-ci
	void loadInventory();

	// Sauvegarde l'inventaire dans un fichier de sauvegarde
	void saveInventory();
	
	// Fonction prenant en param�tre un item. Si l'item existe d�ja, la quantit� est ajout�e, sinon l'item en lui m�me est ajout� � l'inventaire
	void addItem(Item item, int quantity);

	// Constructeur et destructeur
	Inventory();
	~Inventory();

};

