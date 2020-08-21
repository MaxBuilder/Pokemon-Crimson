#include "Inventory.h"

void Inventory::loadInventory() {
	std::ifstream inputFile("assets/save/InventorySave.json");
	json jsonSource;
	jsonSource = json::parse(inputFile);
	
	for (unsigned i = 0; i < jsonSource.size(); i++) {
		int id = jsonSource[std::to_string(i)]["id"].get<int>();
		int nb = jsonSource[std::to_string(i)]["nb"].get<int>();
		items.push_back({ id, nb });
	}
	for (int i = 0; i < 8; i++) {
		items.push_back({i * 100 + 99, 0});
	}
	std::sort(items.begin(), items.end(), [](Item a, Item b) { return a.id < b.id; });

	itRef = items.begin();
	inputFile.close();
}

// Called by save functions in controller
void Inventory::saveInventory() {
	json jsonOutput;
	std::ofstream outputFile("assets/save/InventorySaveOut.json");

	for (unsigned i = 0; i < items.size(); i++) {
		jsonOutput[std::to_string(i)]["id"] = items.at(i).id;
		jsonOutput[std::to_string(i)]["nb"] = items.at(i).nb;
	}

	outputFile << jsonOutput;
	outputFile.close();
}

// Supprime un item. Si le stack est vide, l'item est enlevé 
bool Inventory::removeItem(const int id, const int quantity) {
	Item& item = items.at(id);
	item.nb += quantity;
	if (item.nb == 0) {
		items.erase(items.begin() + id);
		setIterators(id / 100);
		return true;
	}
	else return false;
}

// TO DO
void addItem(const int id, const int quantity) {
	// Si l'item n'existe pas, l'ajouter (basé sur les data d'items)
	// Puis trier le tableau
	return;
}

void Inventory::setIterators(const int catId) {
	bool begin = false;
	itRef = items.begin();
	for (unsigned int i = 0; i < items.size(); i++) {
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
	if (items.at(n).id % 100 == 99) 
		return ret;
	else return items[n];
}

Inventory::Inventory() {}
Inventory::~Inventory() { saveInventory(); }