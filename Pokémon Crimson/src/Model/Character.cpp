#include "Character.h"

Inventory& Character::getInventory() { return inventory; }
PkmnTeam& Character::getPkmnTeam() { return team; }

// Constrcteur et desctructeur
Character::Character() {}
Character::~Character() {}