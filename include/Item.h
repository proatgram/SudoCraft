#include <string>

#ifndef __ITEM_H__
#define __ITEM_H__

class Item {
// Access Identifier
public:
  Item(const std::string& name, int id, int stackNumber) :
  m_name(name),
  m_id(id),
  m_stackNumber(stackNumber) {
 	 
  }

  virtual ~Item() = default;  
    
  int getId() const;
  const std::string& getName() const;
  int getStackNumber() const;
  bool setStackNumber(int stackNumber);	
//Data Members
protected:
	std::string m_name;
	int m_id;
	int m_stackNumber;
	int m_stackNumberMax = 0x63;
};
#endif
