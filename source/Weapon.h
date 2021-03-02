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

	void setRange(const int range);

	void setDurability(int durability);

	int getDamage() const;

	int getRange() const;

	int getDurability() const;

private:    	   
	int m_damage;
	int m_range;
	int m_durability;
}; 
#endif
