#include <cstdio>
#include <string>
#include "Item.h"

#ifndef __WEAPON_H__
#define __WEAPON_H__

class Weapon: public Item {
public:
    Weapon(const std::string& name, int id, int damage, int range, int durability) :
       Item(name, id),
       m_damage(damage),
       m_range(range),
       m_durability(durability)
    {
	
    }

	void setRange(const int range)
		
	{
		m_range = range;
	}
	void setDurability(int durability) {
		m_durability = durability;
	}
	int getDamage() const {return m_damage;}
	int getRange() const {return m_range;}
	int getDurability() const {return m_durability;}
private:    	   
	int m_damage;
	int m_range;
	int m_durability;
}; 
#endif
