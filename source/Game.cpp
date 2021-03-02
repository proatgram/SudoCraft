//Includes from the standered c librarys.
#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>

//Includes for my own .h files.

#include "Item.h"
#include "Tool.h"
#include "Weapon.h"
#include "Character.h"
#include "Inventory.h"

// Defines Inventory  methods:
// Finds a specific item in a vector and deletes it.
void Inventory::removeItem(Item *item) {
  std::vector<Item*>::iterator it = std::find(m_items.begin(), m_items.end(), item);
  if(it != m_items.end()) {
    m_items.erase(it);
  }
}
// Adds item to your inventory.
bool Inventory::addItem(Item *item) {
  if (m_items.size() >= m_capacity) {
    return false;
  }
  else {
    m_items.push_back(item);
    return true;
  }
}
// Makes a list of your items.
const std::vector<Item*> Inventory::getItems() {
  for (int i = 0; i != m_items.size(); i++) {
  }
  
}
// Gets one item from your inventory using a index and if the index is higher than the capacity then just return.
Item* Inventory::getItem(int index) {
  if (index >= m_capacity) {
    
  }
  else {
    return m_items[index];
  }
  
}

// Declares the Item classes methods: 
// Returns the id of an item.
int Item::getId() const {
  return m_id;
}
// Returns the name of an item.
const std::string& Item::getName() const {
  return m_name;
}

// Declares the Weapon classes methods:

// Sets the range of a Weapon instance.

void Weapon::setRange(const int range) {
  m_range = range;
}
// Sets the durability of a Weapon Instance.
void Weapon::setDurability(int durability) {
  m_durability = durability;
}
// Returns the damage that an instance of the Weapon class does.
int Weapon::getDamage() const {
  return m_damage;
}
// Returns the range of the Weapon class instance.
int Weapon::getRange() const {
  return m_range;
}
// Returns the durability of an item in the Weapon class.
int Weapon::getDurability() const {
  return m_durability;
}

// Declares the Tool classes methods: 

// Sets the durability of an item in an instance of the Tool class.

void Tool::setDurability(int durability) {
  m_durability = durability;
}
// Sets the range of an item of an instance of the tool class.
void Tool::setRange(const int range) {
  m_range = range;
}
// Returns the durability of an item in an instance of the Tool class.
int Tool::getDurability() const {
  return m_durability;
}
// Returns the range of an instance of the Tool class.
int Tool::getRange() const {
  return m_range;
}
// Declares the Character classes methods: 

// Retrns the character id of an instance of the Character class.

int Character::getCharacterID() const {
  return m_characterID;
}
// Returns the character name of an instacne of the Character class.
const std::string& Character::getCharacterName() const {
  return m_name;
}
// Returns the levels of an instance of a Character class.
int Character::getLevels() const {
  return m_level;
}
// Sets up the character.
int Character::characterSetup(const std::string fileName) {
  return 0;
}
// This method prints the weapon info.
void printWeaponInfo(const Weapon& weapon)
{
		// Axe ID: 1 damage: 5 Range: 1
		printf("%s ID: %d Damage: %d Range: %d Durability: %d\n", 
		weapon.getName().c_str(),
		weapon.getId(),
		weapon.getDamage(),
		weapon.getRange(),
		weapon.getDurability());
}
// This method prints the tool info.
void printToolInfo(const Tool& tool)
{
		// Shovel ID: 4 Damage: DEFAULT Range: 2
		printf("%s ID: %d Damage: %d Range: %d Durability: %d\n",
		tool.getName().c_str(),
		tool.getId(),
		1,
		tool.getRange(),
		tool.getDurability());
}
// This method prints the Character info.
void printCharacterInfo(const Character& character) {
	printf("Name: %s Levels: %d Character ID: %d\n",
	character.getCharacterName().c_str(),
	character.getLevels(),
	character.getCharacterID());
}
// This is the main method that gets called as soon as the program starts.
int main() {
  // These sets up the instances of the Tool,Weapon, and Character classes.
	Character Azdelth(std::string("Azdelth"), 0, 8647);
	Weapon woodenSword(std::string("Wooden Sword"), 1, 3, 2, 100);
	Weapon primitiveClub(std::string("Primitive Club"), 2, 3, 2, 100);
	Weapon bow(std::string("Bow"), 3, 4, 25, 100);
	Tool woodenShovel(std::string("Wooden Shovel"), 4, 100, 2);
  // These call the methods declaired inside the Tool and Weapon class.
	woodenSword.setDurability(99);
	woodenShovel.setDurability(79);
  // These call the print info classes defined in the Game.cpp file.
	printWeaponInfo(woodenSword);
	printWeaponInfo(bow);
	printWeaponInfo(primitiveClub);
	printToolInfo(woodenShovel);
	printCharacterInfo(Azdelth);
	
}
