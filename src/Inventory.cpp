#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include "../include/Inventory.h"
#include "../include/Item.h"
#include "../include/Weapon.h"
#include "../include/Tool.h"


// Defines Inventory methods:

// Defines Inventory Constructor
Inventory::Inventory() {
  std::vector<Item*>* items = new std::vector<Item*>;
  m_items = items;
}


// Fins a specific item in a vector (Inventory) and deletes it.
void Inventory::removeItem(Item *item) {
  std::vector<Item*>::iterator it = std::find(m_items->begin(), m_items->end(), item);
  if (it != m_items->end()) {
    m_items->erase(it);
  }
}

// Adds item to the vector (Inventory)
bool Inventory::addItem(Item *item) {
  if (m_items->size() >= m_capacity) {
    return false;
  }
  else {
    m_items->push_back(item);
    return true;
  }
  return true;
}

// Makes a list of your items in your inventory
Item* Inventory::getItem(int index) {
  if (index >= m_capacity) {
    return 0x00;
  }
  else {
    return m_items->at(index);
  }
}
std::vector<Item*>* Inventory::getVector() {
	return m_items;
}
