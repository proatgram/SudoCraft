#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include "Item.h"

#ifndef __INVENTORY_H__
#define __INVENTORY_H__

class Inventory {
public:

  Inventory();

  virtual ~Inventory() = default;

  bool addItem(Item* item);

  const std::vector<Item*> getItems();

  Item* getItem(int index);

  void removeItem(Item* item);
	
  std::vector<Item*>* getVector();

protected:
  uint8_t m_capacity = 0x2E;
  std::vector<Item*>* m_items;
};

#endif
