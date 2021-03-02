#include <cstdint>
#include <vector>
#include <algorithm>

#ifndef __INVENTORY_H__
#define __INVENTORY_H__

class Inventory {
public:
  Inventory(uint8_t capacity) : 
  m_capacity(capacity)
  {
 
  }
  Inventory(uint8_t capacity, const std::vector<Item*>& items) : 
  m_items(items)
  {

  }

  //virtual ~Inventory = default;

  bool addItem(Item* item);

  const std::vector<Item*> getItems();

  Item* getItem(int index);

  void removeItem(Item* item);

protected:
  uint8_t m_capacity;
  std::vector<Item*> m_items;
};

#endif