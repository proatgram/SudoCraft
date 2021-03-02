#include <string>

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
	virtual ~Character() = default;
	int getCharacterID() const;
	const std::string& getCharacterName() const;
	int getLevels() const;
	int characterSetup(const std::string fileName);
  
private:
	std::string m_name;
	int m_level;
	const int m_characterID;
};
#endif