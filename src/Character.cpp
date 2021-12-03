#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include "../include/Character.h"
#include "../include/Inventory.h"

// Declares the Character Class methods:

// Returns the character ID of an instance of the Character Class.
int Character::getCharacterID() const {
	return m_characterID;
}

// Returns the character name of an instance of a Character Class.
const std::string& Character::getCharacterName() const {
	return m_name;
}

// Return the levels of an instance of a Character Class.
int Character::getLevels() const {
	return m_level;
}

// Sets up the Character Class Instance. ## NOT FINISHED ##
int Character::characterSetup(const std::string fileName) {
	return 0x00;
}
Inventory* Character::getInventory() {
	return inventory;
}
