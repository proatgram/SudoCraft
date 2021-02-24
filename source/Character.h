#include <cstdio>
#include <string>

class Character {
public:
	Character(const std::string& name, const int levels, const int characterID) : 
		m_name(name),
		m_levels(levels),
		m_characterID(characterID)
	{
		
	}
	
	virtual ~Character() = default;
	int getCharacterID() const {return m_characterID;}
	const std::string& getCharacterName() const {return m_name;}
	int getLevels() const {return m_levels;}
private:
	std::string m_name;
	int m_levels;
	const int m_characterID;
};
