#include <vector>
#include <string>
#include <utility>
#include <tuple>

#include "WorldGen.h"
#include "Blocks.h"
#include "Utils.h"

#ifndef __WORLD__
#define __WORLD__

class World {
public:
	World(int size_x, int size_y, int size_z, int worldSeed, int biomeSeed, int blockSeed);

	BlockDataStruct getBlock(int x, int y, int z);

private:
	int m_size_x;
	int m_size_y;
	int m_size_z;
	WorldGeneration m_heightGenerate;
	WorldGeneration m_blockGenerate;
	std::vector<std::vector<std::vector<std::vector<std::pair<std::tuple<int, int, int>, float>>>>> m_heightMap;
	std::vector<std::vector<std::vector<std::vector<std::pair<std::tuple<int, int, int>, float>>>>> m_biomeMap;
	std::vector<std::vector<std::vector<std::vector<BlockDataStruct>>>> m_blocks;
};

#endif