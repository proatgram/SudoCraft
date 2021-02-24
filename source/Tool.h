#include <cstdio>
#include <string>
#include "Item.h"

#ifndef __TOOL_H__
#define __TOOL_H__

class Tool: public Item {
public:
	Tool(const std::string& name, int id, int durability, int range) :
		Item(name, id),
		m_durability(durability),
		m_range(range)
	{
	}
	void setDurability(int durability) {
		m_durability = durability;
		}

	void setRange(const int range) {
		m_range = range;
		}
	int getDurability() const {return m_durability;}
	int getRange() const {return m_range;}

private:
	int m_durability;
	int m_range;
};
#endif
