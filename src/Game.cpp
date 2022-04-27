#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>

#include "Item.h"
#include "Tool.h"
#include "Weapon.h"
#include "Character.h"
#include "Inventory.h"
#include "ItemLists.h"
#include "Craft.h"
#include "SafeData.hpp"
#include "GameUI.h"
#include "World.h"

// This method prints the weapon info.
void printWeaponInfo(const Weapon& weapon)
{
		// Axe ID: 1age: 5 Range: 1
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
	printf("Name: %s Levels: 0x%x Character ID: 0x%x\n",
	character.getCharacterName().c_str(),
	character.getLevels(),
	character.getCharacterID());
}
// This is the main method that gets called as soon as the program starts.
int main() {
	Character Azdelth("Azdelth", 0x00, 0x1234);
	Craft craft;
	Item* Log = new Item(itemName[0x08], 0x08, 0x00);
	Item* Stick = new Item(itemName[0x04], 0x04, 0x01);
	Item* Leather = new Item(itemName[0x0D], 0x0D, 0x00);
	Item* String = new Item(itemName[0x0A], 0x0A, 0x00);
	Weapon* weapon1 = new Weapon(itemName[0x00], 0x00, itemDamage[0x00], itemRange[0x00], itemDurability[0x00], 0x00);
	Azdelth.inventory->addItem(Log);
	Azdelth.inventory->addItem(Stick);
	Azdelth.inventory->addItem(Leather);
	Azdelth.inventory->addItem(String);
	Azdelth.inventory->addItem(weapon1);
	Weapon* weapon = reinterpret_cast<Weapon*>(craft.craftItem(0x00, Azdelth.getInventory()));
	Azdelth.inventory->addItem(weapon);
	printf("Crafted Item:\n Name: %s\n ID Number: %d\n Damage: %d\n Range: %d\n", Azdelth.inventory->getItem(0x04)->getName().c_str(), Azdelth.inventory->getItem(0x04)->getId(), reinterpret_cast<Weapon*>(Azdelth.inventory->getItem(0x04))->getDamage(), reinterpret_cast<Weapon*>(Azdelth.inventory->getItem(0x04))->getRange());
	printCharacterInfo(Azdelth);
	World world(17, 17, 17, 11231212, 12342341, 4321234);
	//world.getBlock(12, 12, 12);
	
	
	for (int x = 0; x < 1000; x++) {
		for (int y = 0; y < 1000; y++) {
			for (int z = 0; z < 1000; z++) {
				world.getBlock(x, y, z);
			}
		}
	}
	
}
