#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include "../include/Item.h"
#include "../include/Weapon.h"

// Declares the Weapon Class methods:


// Sets the range of a Weapon instance.
void Weapon::setRange(const int range) {
  m_range = range;
}

// Sets the durability of a Weapon Instance.
void Weapon::setDurability(int durability) {
	m_durability = durability;
}

// Return the damage that an instance of the Weapon Class does.
int Weapon::getDamage() const {
	return m_damage;
}

// Returns the range of the Weapon Class insance.
int Weapon::getRange() const {
	return m_range;
}
int Weapon::getDurability() const {
	return m_durability;
}
