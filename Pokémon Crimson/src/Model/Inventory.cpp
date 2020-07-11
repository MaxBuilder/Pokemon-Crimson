#include "Inventory.h"

void Inventory::loadInventory() {
	// Future serialization of the inventory
	// TO DO : Serialize + saveInventory
	//items.push_back({ 7, 8 });

	// Test loading from JSON file
	std::ifstream inputFile("data/source.json");
	json jsonSource;
	jsonSource = json::parse(inputFile);
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < jsonSource[std::to_string(i)].size(); j++) {
			int id = std::stoi(jsonSource[std::to_string(i)][std::to_string(j)]["id"].get<std::string>()) + i * 100;
			int nb = std::stoi(jsonSource[std::to_string(i)][std::to_string(j)]["nb"].get<std::string>());
			items.push_back({ id, nb });
		}
	}
	itRef = items.begin();
}

void Inventory::saveInventory() {
	return;
}

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