#include <cstdio>
#include <string>

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class Character {
public:
	Character(const std::string& name, const int levels, const int characterID) : 
		m_name(name),
		m_level(levels),
		m_characterID(characterID)
	{
		
	}
	
	virtual ~Character() = default;
	int getCharacterID() const {return m_characterID;}
	const std::string& getCharacterName() const {return m_name;}
	int getLevels() const {return m_level;}
  
private:
	std::string m_name;
	int m_level;
	const int m_characterID;
};
#endif
