#include "Inventory.h"

void Inventory::loadInventory() {
	// Future serialization of the inventory
	// TO DO : Serialize + saveInventory
	items.push_back({ 7, 8 });

	// Test loading from JSON file
}

void Inventory::saveInventory() {
	return;
}

void Inventory::addItem(int id, int quantity) {
	return;
}

Inventory::Inventory() {}
Inventory::~Inventory() {}