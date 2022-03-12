#include <vector>
#include <string>
#include "WorldGen.h"


#ifndef __WORLD__
#define __WORLD__

class World {
public:
	World(int size_x, int size_y, int seed);

private:
	int m_size_x;
	int m_size_y;
	WorldGeneration m_generate;
	float m_heightMap;
	struct m_blockData {
		unsigned short int blockType;
		std::string nbtData;
	};
	std::vector<m_blockData> m_blocksPositive_y;
	std::vector<m_blockData> m_blocksPositive_x;
	std::vector<m_blockData> m_blocksNegative_y;
	std::vector<m_blockData> m_blocksNegative_x;
};

#endif