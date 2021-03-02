#include <cstdio>
#include <string>

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class Character {
public:

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
