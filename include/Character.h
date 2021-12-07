#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include "Inventory.h"

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class Character {
public:
  Character(std::string name, int levels, int characterId) : 
  m_name(name),
  m_level(levels),
  m_characterID(characterId)
  {

  }
	Inventory* inventory = new Inventory;
	virtual ~Character() = default;
	int getCharacterID() const;
	const std::string& getCharacterName() const;
	int getLevels() const;
	int characterSetup(const std::string fileName);
	Inventory* getInventory();
	struct position {
		int32_t x = 0x00;
		int32_t y = 0x00;
		int32_t z = 0x00;
	};
private:

	std::string m_name;
	int m_level;
	const int m_characterID;
};
#endif
