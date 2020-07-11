#include "Inventory.h"

void Inventory::loadInventory() {
	std::ifstream inputFile("data/save/InventorySave.json");
	json jsonSource;
	jsonSource = json::parse(inputFile);
	
	// Old
	/*for (int i = 0; i < 8; i++) {
		for (int j = 0; j < jsonSource[std::to_string(i)].size(); j++) {
			int id = std::stoi(jsonSource[std::to_string(i)][std::to_string(j)]["id"].get<std::string>()) + i * 100;
			int nb = std::stoi(jsonSource[std::to_string(i)][std::to_string(j)]["nb"].get<std::string>());
			items.push_back({ id, nb });
		}
	}*/
	for (auto i = 0; i < jsonSource.size(); i++) {
		int id = jsonSource[std::to_string(i)]["id"].get<int>();
		int nb = jsonSource[std::to_string(i)]["nb"].get<int>();
		items.push_back({ id, nb });
	}

	itRef = items.begin();
	inputFile.close();
}

// Called by save functions in controller
void Inventory::saveInventory() {
	json jsonOutput;
	std::ofstream outputFile("data/InventorySave.json");

	for (int i = 0; i < items.size(); i++) {
		jsonOutput[std::to_string(i)]["id"] = items[i].id;
		jsonOutput[std::to_string(i)]["nb"] = items[i].nb;
	}

	outputFile << jsonOutput;
	outputFile.close();
}

// Prends en paramètre l'id de l'item. Si il existe déja, seule la quantité est ajoutée
// sinon l'instance de l'item est ajoutée dans le vector. Un tri est effectué suite à cet ajout
// pour conserver les id dans un ordre croissant (itérateurs).
void Inventory::addItem(const int id, const int quantity) {
	return;
}

void Inventory::setIterators(const int catId) {
	bool begin = false;
	for (int i = 0; i < items.size(); i++) {
		if (!begin) {
			if (items[i].id >= catId * 100) {
				itBegin = items.begin() + i;
				begin = true;
			}
		}
		if (items[i].id > catId * 100 + 99 and begin) {
			itEnd = itRef + i - 1;
			return;
		}
	}
	itEnd = itRef + items.size() - 1;
}

Item& Inventory::getItem(const int n) {
	return items[n];
}

Inventory::Inventory() {}
Inventory::~Inventory() {}