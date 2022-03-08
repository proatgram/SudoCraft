#include <vector>
#include "../include/WorldGen.h"


#ifndef __WORLD__
#define __WORLD__

class World {
public:
	World(int size_x, int size_y);

private:
	int m_size_x;
	int m_size_y;
	float m_heightMap;
};

#endif