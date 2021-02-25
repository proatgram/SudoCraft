#include <cstdio>
#include <string>
#include "Character.h"

#ifndef __INVENTORY_H__
#define __INVENTORY_H__

class Inventory {
public:
  Inventory()
  {

  }

  int getSlotNum(const std::string& name, const int itemID) const {
    return 0;
   }
  const std::string& getName(const int itemSlot, const int itemID) const {
    const std::string& temp = "0";
    return temp;
  }
  const std::string& getItemClass(const std::string& name, const int itemSlot, const int temID) const {
    const std::string& temp = "0";
    return temp;
  }
  int getDurability(const std::string& name, const int itemID) const {
    return 0;
  }
  void setItem(const std::string& itemName, const int itemID, const int itemDurability, const int itemDamage, const std::string& itemClass) {
    
  }

  void removeItem(const std::string itemName, const int itemSlot, const int itemID){
    
  }
protected:

};

#endif
