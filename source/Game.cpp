#include <cstdio>
#include <SDL/SDL.h>
#include <string>
#include "Item.h"
#include "Tool.h"
#include "Weapon.h"
#include "Character.h"
#include "Inventory.h"

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

int main() {
//	setupItems();
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
	
}
