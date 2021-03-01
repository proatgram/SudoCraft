#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include "Character.h"

#ifndef __INVENTORY_H__
#define __INVENTORY_H__

class Inventory {
public:
  Inventory(uint8_t capacity) : 
  m_capacity(capacity)
  {

  }
     

protected:
  uint8_t m_capacity
};

#endif
