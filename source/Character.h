#include <cstdio>
#include <string>

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class Character {
public:

	virtual ~Character() = default;
	int getCharacterID() const {return m_characterID;}
	const std::string& getCharacterName() const {return m_name;}
	int getLevels() const {return m_level;}
	int characterSetup(const std::string fileName) {
		
		return 0;
}
  
private:
	std::string m_name;
	int m_level;
	const int m_characterID;
};
#endif
