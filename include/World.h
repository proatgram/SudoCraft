#include <vector>
#include <string>
#include "WorldGen.h"


#ifndef __WORLD__
#define __WORLD__

class World {
public:
	struct BlockDataStruct {
		signed short int coordSign;
		unsigned short int blockType;
		std::string nbtData;
	};

	World(int size_x, int size_y, int size_z, int seed);

	BlockDataStruct getBlock(int x, int y, int z);

private:
	int m_size_x;
	int m_size_y;
	int m_size_z;
	WorldGeneration m_generate;
	BlockDataStruct m_blocks[][][][];
};

#endif