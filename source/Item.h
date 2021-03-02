#include <cstdio>
#include <string>

#ifndef __ITEM_H__
#define __ITEM_H__

class Item {
// Access Identifier
public:
    Item(const std::string& name, int id) :
       m_name(name),
       m_id(id)
    {
	 	 
	  }
	
	virtual ~Item() = default;  
    
    int getId() const;
    const std::string& getName() const;
    
//Data Members
protected:
	std::string m_name;
	int m_id;
};
#endif
