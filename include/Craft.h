#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include "Item.h"
#include "Tool.h"
#include "Weapon.h"
#include "Inventory.h"

class Craft {
	
	public:	
		 Item * craftItem(int itemID, Inventory* inventory);

	private:
		 int maxCraftAmount = 0x63;

};

