#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include "Item.h"
#include "Tool.h"

// Declares the Tool classes methods:

// Sets durability of an item in an instance of the Tool Class.
void Tool::setDurability(int durability) {
	m_durability = durability;
}

// Sets the range of an item in an instance of the Tool Class.
void Tool::setRange(const int range) {
	m_range = range;
}

// Retruns the durability of an item in an instance of the Tool Class.
int Tool::getDurability() const {
	return m_range;
}

// Returns the range of an instance of a Tool Class.
int Tool::getRange() const {
 	return m_range;
}

