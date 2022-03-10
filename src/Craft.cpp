#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include <climits>
#include "Craft.h"
#include "ItemLists.h"
#include "Item.h"
#include "Weapon.h"
#include "Tool.h"
#include "Inventory.h"

Item * Craft::craftItem(int itemID, Inventory* inventory) {
	if (itemMake[itemID][0x00] == INT_MAX) {
		//printf("INT_MAX\n");
	}
	uint8_t num1 = 0x00;
	for (uint8_t times = 0x00; times < CRAFTINGREDIENTS; times++) {
		if (itemMake[itemID][times] != INT_MAX) {
			num1++;
		}
	}
	uint8_t num = 0x00;
	int (*itemlist)[2] = new int[num1][0x02];
	for (uint8_t times = 0x00; times < num1; times++) {
		for (uint8_t times1 = 0x00; times1 < 0x02; times1++) {
			itemlist[times][times1] = 0xFF;
		}
	}
	uint8_t amountOfNeeded = 0x00;
	uint8_t amountHave = 0x00;
	for (uint8_t times = 0x00; times < num1; times++) {
		uint8_t numb = 0x00;
		//printf("Slot: 0x%x\n", times);
		for (uint8_t counter = 0x00; counter < num1; counter++) {
			//printf("Times: 0x%x Counter: 0x%x Numb: 0x%x \n", times, counter, numb);
			for (uint8_t mumberlol = 0x00; mumberlol < num1; mumberlol++) {
				for (uint8_t numbumberlol = 0x00; numbumberlol < 0x02; numbumberlol++) {
					//printf("itemlist[0x%x][0x%x] itemlist[0x%x] = { 0x%x, 0x%x } \n", mumberlol, numbumberlol, mumberlol, itemlist[mumberlol][0x00], itemlist[mumberlol][0x01]);
				}
			}
			if (itemlist[counter][0x00] == itemMake[itemID][times]) {
				if (itemlist[counter][0x01] == 0xFF) {
					itemlist[counter][0x01] = 0x01;
				}
				else {
					itemlist[counter][0x01]++;
				}
			}
			else {
				numb++;
			}
		}
		if (numb == num1) {
			itemlist[times][0x00] = itemMake[itemID][times];
			//printf("Adding Item to List: Item ID Added: 0x%x What's in the List: 0x%x\n", itemMake[itemID][times], itemlist[times][0x00]);
		}
	}
        for (uint8_t times = 0x00; times < num1; times++) {
                if (itemlist[times][0x00] != 0xFF) {
                        amountOfNeeded++;
                }
        }
	for (uint8_t times = 0x00; times < num1; times++) {
		for (uint8_t findItem = 0x00; findItem < inventory->getVector()->size(); findItem++) {
			for (uint8_t isItem = 0x00; isItem < num1; isItem++) {
				switch (itemClass[inventory->getItem(findItem)->Item::getId()]) {
					case 0x00 : {
						//printf("Item Stack: 0x%x List Stack: 0x%x \n", inventory->getItem(findItem)->Item::getStackNumber(), itemlist[isItem][0x01]);
						if (inventory->getItem(findItem)->Item::getId() == itemlist[isItem][0x00]) {
							if (inventory->getItem(findItem)->Item::getStackNumber() == itemlist[isItem][0x01]) {
								amountHave++;
								//printf("Item\n");
							}
						}
						break;
					}
					case 0x01 : {
				    		if (reinterpret_cast<Weapon*>(inventory->getItem(findItem))->Item::getId() == itemlist[isItem][0x00]) {
			    				if (reinterpret_cast<Weapon*>(inventory->getItem(findItem))->Item::getStackNumber() == itemlist[isItem][0x01]) {
							       amountHave++;
							}
					 	}
						break;
					}
			    		case 0x02 : {
						if (reinterpret_cast<Tool*>(inventory->getItem(findItem))->Item::getId() == itemlist[isItem][0x00]) {
			    				if (reinterpret_cast<Tool*>(inventory->getItem(findItem))->Item::getStackNumber() == itemlist[isItem][0x01]) {
								amountHave++;
							}
						}
					}				
					case 0x03 : {
						break;
					}
				}
			}
		}
	}
	//printf("amountOfNeeded: 0x%x amountHave: 0x%x\n", amountOfNeeded, amountHave);
	if (amountOfNeeded == amountHave) {
                switch (itemClass[itemID]) {
                        case 0x00 : {

                                Item* item = new Item(itemName[itemID], itemID, 0x00);
                                return item;
                                break;
                        }
                        case 0x01 : {
                                Weapon* item = new Weapon(itemName[itemID], itemID, itemDamage[itemID], itemRange[itemID],  itemDurability[itemID], 0x00);
                                Item* nItem = item;
                                return nItem;
                                break;
                        }
                        case 0x02 : {

                                Tool* item = new Tool(itemName[itemID], itemID, itemRange[itemID], itemDurability[itemID], 0x00);
                                Item* nItem = item;
                                return nItem;
                                break;
                        }
                        case 0x03 : {

                                break;
                        }

                }
	}
	return 0x00;
}
/*
	for (uint8_t times = 0x00; times < num1; times++) {
		for (uint8_t slot = 0x00; slot < inventory->getVector()->size() - 0x02; slot++) {
			switch (itemClass[inventory->getItem(slot)->Item::getId()]) {
				case 0x00 : {

					if (inventory->getItem(slot)->Item::getId() == itemMake[itemID][times]) {
						num++;
					}
					break;
				}
				case 0x01 : {

					if (reinterpret_cast<Weapon*>(inventory->getItem(slot))->Weapon::getId() == itemMake[itemID][times]) {
						num++;
					}
					break;
				}
				case 0x02 : {

					if (reinterpret_cast<Tool*>(inventory->getItem(slot))->Tool::getId() == itemMake[itemID][times]) {
						num++;
					}
					break;
				}
				case 0x03 : {

					break;
				}
			}

		}
	}
	if (num == num1) {
		switch (itemClass[itemID]) {
			case 0x00 : {

				Item* item = new Item(itemName[itemID], itemID, 0x00);
				return item;
				break;
			}
			case 0x01 : {
				Weapon* item = new Weapon(itemName[itemID], itemID, itemDamage[itemID], itemRange[itemID],  itemDurability[itemID], 0x00);
				Item* nItem = item;
				return nItem;
				break;
			}
			case 0x02 : {

				Tool* item = new Tool(itemName[itemID], itemID, itemRange[itemID], itemDurability[itemID], 0x00);
				Item* nItem = item;
				return nItem;
				break;
			}
			case 0x03 : {

				break;
			}

		}
	}	
	return 0x00;
}
*/
