//The Includes for the current logic.
#include <cstdio>
#include <cstdint>
//#include <SDL/SDL.h>
#include <string>
#include <algorithm>
#include "Item.h"
#include "Tool.h"
#include "Weapon.h"
#include "Character.h"
#include "Inventory.h"

// Defines Inventory  methods:
void Inventory::removeItem(Item *item) {
  std::vector<Item*>::iterator it = std::find(m_items.begin(), m_items.end(), item);
  if(it != m_items.end()) {
    m_items.erase(it);
  }
}

bool Inventory::addItem(Item *item) {
  if (m_items.size() >= m_capacity) {
    return false;
  }
  else {
    m_items.push_back(item);
    return true;
  }
}

const std::vector<Item*> Inventory::getItems() {
  for (int i = 0; i != m_items.size(); i++) {
  }
  
}

Item* Inventory::getItem(int index) {
  if (index >= m_capacity) {
    
  }
  else {
    return m_items[index];
  }
  
}

// Declares the Item classes methods: 

int Item::getId() const {
  return m_id;
}

const std::string& Item::getName() const {
  return m_name;
}

// Declares the Weapon classes methods:

void Weapon::setRange(const int range) {
  m_range = range;
}

void Weapon::setDurability(int durability) {
  m_durability = durability;
}

int Weapon::getDamage() const {
  return m_damage;
}

int Weapon::getRange() const {
  return m_range;
}

int Weapon::getDurability() const {
  return m_durability;
}

// Declares the Tool classes methods: 

void Tool::setDurability(int durability) {
  m_durability = durability;
}

void Tool::setRange(const int range) {
  m_range = range;
}

int Tool::getDurability() const {
  return m_durability;
}

int Tool::getRange() const {
  return m_range;
}
// Declares the Character classes methods: 

int Character::getCharacterID() const {
  return m_characterID;
}
const std::string& Character::getCharacterName() const {
  return m_name;
}

int Character::getLevels() const {
  return m_level;
}

int Character::characterSetup(const std::string fileName) {
  return 0;
}

/*
class Shovel: public Tool {
public:
	Shovel(const std::string& name, int durability) : 
		Tool(name, SHOVEL_ID),
		m_durability(durability)
	{
		
	}
	
	void setDurability(const int durability) {
		m_durability = durability;	
	}
	int getDurability() const {return m_durability;}	
private:
	int m_durability
	static const int SHOVEL_ID = 4;
};
*/

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

void printCharacterInfo(const Character& character) {
	printf("Name: %s Levels: %d Character ID: %d\n",
	character.getCharacterName().c_str(),
	character.getLevels(),
	character.getCharacterID());
}
/*
void setupItems() {
	Weapon* woodenSword = new Weapon(std::string("Wooden Sword"), 1, 3, 2, 100);
	Weapon* primitiveClub = new Weapon(std::string("Primitive Club"), 2, 3, 2, 100);
	Weapon* bow = new Weapon(std::string("Bow"), 3, 4, 25, 100);
	Tool woodenShovel(std::string("Wooden Shovel"), 4, 100, 2);
       delete woodenSword;
       woodenSword = nullptr;       
}
*/
/*
std::vector<int>* vectorTest() {
  //int g2*; 
  std::vector<int> *g2 = new std::vector<int>();
  g2->push_back(1);
  //g2.push_back(2);
  //printf("Pointer to g2: %d", *g2[1]);
  return g2;
}
int main() {
  //function();ls

  std::vector<int>* g2 = vectorTest();
  printf("pointer g2 = 0x%x\nValue of vector g2 slot 1: ", g2);
  g2->push_back(56);
  printf(" %d\n",g2->at(0));
  delete g2;
  g2 = nullptr;
}
 */
int main() {
//	setupItems();
  /*
	Character Azdelth(std::string("Azdelth"), 0, 8647);
	Weapon woodenSword(std::string("Wooden Sword"), 1, 3, 2, 100);
	Weapon primitiveClub(std::string("Primitive Club"), 2, 3, 2, 100);
	Weapon bow(std::string("Bow"), 3, 4, 25, 100);
	Tool woodenShovel(std::string("Wooden Shovel"), 4, 100, 2);
	woodenSword.setDurability(99);
	woodenShovel.setDurability(79);
	printWeaponInfo(woodenSword);
	printWeaponInfo(bow);
	printWeaponInfo(primitiveClub);
	printToolInfo(woodenShovel);
	printCharacterInfo(Azdelth);
	*/
}
