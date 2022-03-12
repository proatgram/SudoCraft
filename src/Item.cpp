#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include "Item.h"

int Item::getId() const {
  return m_id;
}

const std::string& Item::getName() const {
  return m_name;
}

int Item::getStackNumber() const {
	return m_stackNumber;
}
bool Item::setStackNumber(int stackNumber) {
	if (stackNumber <= m_stackNumberMax) {
		m_stackNumber = stackNumber;
		return true;
	}
	else {
		return false;
	}
}

