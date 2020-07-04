#include "Inventory.h"

void Inventory::loadInventory() {
	// Future serialization of the inventory
	// TO DO : Serialize + saveInventory
	items.push_back({ 7, 8 });
}

Inventory::Inventory() {}
Inventory::~Inventory() {}