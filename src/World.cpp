#include <cmath>
#include <cstdlib>
#include <utility>

#include "World.h"
#include "Utils.h"
#include "Blocks.h"

World::World(int size_x, int size_y, int size_z, int worldSeed, int biomeSeed, int blockSeed) :
	m_size_x(size_x),
	m_size_y(size_y),
	m_size_z(size_z),
	m_heightGenerate(worldSeed),
	m_blockGenerate(blockSeed)
{

}



BlockDataStruct World::getBlock(int x, int y, int z) {
	unsigned int location = 0;

	if (m_blocks[abs(x)][abs(y)][abs(z)].size() != 0) {
		for (unsigned long int times = 0; times < m_blocks[abs(x)][abs(y)][abs(z)].size(); times++) {
			if (m_blocks[abs(x)][abs(y)][abs(z)].at(times).x == x && m_blocks[abs(x)][abs(y)][abs(z)].at(times).y == y && m_blocks[abs(x)][abs(y)][abs(z)].at(times).z == z) {
				return m_blocks[abs(x)][abs(y)][abs(z)].at(times);
			}
		}
		m_heightMap[abs(x)][abs(y)][abs(z)].push_back(std::make_pair(std::make_tuple(x, y, z), m_heightGenerate.generate(x, y, z)));

		for (unsigned int times = 0; times < m_heightMap[abs(x)][abs(y)][abs(z)].size(); times++) {
			if (std::get<0>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == x && std::get<1>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == y && std::get<2>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == z) {
				location = times;
			}
		}

		if (Utils::Math::inRange(Utils::BiomeConstraints::oceanMin, Utils::BiomeConstraints::oceanMax, m_heightMap[abs(x)][abs(y)][abs(z)].at(location).second)) {
			m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::water, "\n"));
		}

		if (Utils::Math::inRange(Utils::BiomeConstraints::desertMin, Utils::BiomeConstraints::desertMax, m_heightMap[abs(x)][abs(y)][abs(z)].at(location).second)) {
			if (Utils::Math::inRange(Utils::BiomeBlockConstraints::desert::gravel::min, Utils::BiomeBlockConstraints::desert::gravel::max, m_blockGenerate.generate(x, y, z))) {
				m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::gravel, "\n"));
			}
			if (Utils::Math::inRange(Utils::BiomeBlockConstraints::desert::sand::min, Utils::BiomeBlockConstraints::desert::sand::max, m_blockGenerate.generate(x, y, z))) {
				m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::sand, "\n"));
			}
		}
	

	}
	else {

	}
}