#include <string>
#include "Item.h"

#ifndef __TOOL_H__
#define __TOOL_H__

class Tool: public Item {
public:
	Tool(const std::string& name, int id, int range, int durability, int stackNumber) :
		Item(name, id, stackNumber),
		m_range(range),
		m_durability(durability)
	{
	}

	virtual ~Tool() = default;

	void setDurability(int durability);

	void setRange(const int range);

	int getDurability() const;

	int getRange() const;

private:
	int m_durability;
	int m_range;
};
#endif
