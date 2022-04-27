#include <cmath>
#include <cstdlib>
#include <utility>

#include "World.h"
#include "Utils.h"
#include "Blocks.h"
#include "noise/noise.h"

World::World(int size_x, int size_y, int size_z, int worldSeed, int biomeSeed, int blockSeed) :
	m_size_x(size_x),
	m_size_y(size_y),
	m_size_z(size_z),
	m_heightGenerate(worldSeed),
	m_biomeGenerate(biomeSeed),
	m_blockGenerate(blockSeed)
{

}



BlockDataStruct World::getBlock(int x, int y, int z) {
	std::printf("X: %d, Y: %d, Z: %d\n", x, y, z);
	// Checks to see if there is an element at X, Y, and Z, and if not, do something based on where
	// the value stops
	if (m_blocks.size() > abs(x)) {
		if (m_blocks[abs(x)].size() > abs(y)) {
			if (m_blocks[abs(x)][abs(y)].size() > abs(z)) {
				if (m_blocks[abs(x)][abs(y)][abs(z)].size() > 0) {
					for (unsigned long int times = 0; times < m_blocks[abs(x)][abs(y)][abs(z)].size(); times++) {
						if (m_blocks[abs(x)][abs(y)][abs(z)].at(times).x == x && m_blocks[abs(x)][abs(y)][abs(z)].at(times).y == y && m_blocks[abs(x)][abs(y)][abs(z)].at(times).z == z) {
							return m_blocks[abs(x)][abs(y)][abs(z)].at(times);
						}
					}
				}
				else {

				}
			}
			else {
				if (m_heightMap[abs(x)][abs(y)].size() < abs(z)) {
					m_heightMap[abs(x)][abs(y)].resize(abs(z));
				}
				m_heightMap[abs(x)][abs(y)].emplace(m_heightMap[abs(x)][abs(y)].begin() + abs(z));

				std::tuple<int, int, int> coords = std::make_tuple(x, y, z);
				float height = m_heightGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0);
		 		std::pair<std::tuple<int, int, int>, float> heightPair = std::make_pair(coords, height);
				m_heightMap[abs(x)][abs(y)][abs(z)].push_back(heightPair);

				if (m_biomeMap[abs(x)][abs(y)].size() < abs(z)) {
					m_biomeMap[abs(x)][abs(y)].resize(abs(z));
				}
				m_biomeMap[abs(x)][abs(y)].emplace(m_biomeMap[abs(x)][abs(y)].begin() + abs(z));
				float biome = m_biomeGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0);
				std::pair<std::tuple<int, int, int>, float> biomePair = std::make_pair(coords, biome);
				m_biomeMap[abs(x)][abs(y)][abs(z)].push_back(biomePair);

				if (m_blocks[abs(x)][abs(y)].size() < abs(z)) {
					m_blocks[abs(x)][abs(y)].resize(abs(z));
				}
				m_blocks[abs(x)][abs(y)].emplace(m_blocks[abs(x)][abs(y)].begin() + abs(z));
				// Sorts through the X, Y, and Z coordinate vector for the specific signed coordinate.
				int heightIndex = -1;
				for (int times = 0; times < m_heightMap[abs(x)][abs(y)][abs(z)].size(); times++) {
					if (std::get<0>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == x && std::get<1>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == y && std::get<2>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == z) {
						heightIndex = times;
					}
				}
				if (heightIndex == -1) {
					if (Utils::Math::inRange(Utils::BiomeConstraints::desertMin, Utils::BiomeConstraints::desertMax, m_heightMap[abs(x)][abs(y)][abs(z)].at(heightIndex).second)) {
						if (Utils::Math::inRange(Utils::BiomeBlockConstraints::desert::gravel::min, Utils::BiomeBlockConstraints::desert::gravel::max, m_blockGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0))) {
							m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::gravel, "\n"));
						}
						if (Utils::Math::inRange(Utils::BiomeBlockConstraints::desert::sand::min, Utils::BiomeBlockConstraints::desert::sand::max, m_blockGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0))) {
							m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::sand, "\n"));
						}
						printf("%s", m_blocks[abs(x)][abs(y)][abs(z)].at(0).block.name.c_str());
					}
				}
			}

		}
		else {
			if (m_heightMap[abs(x)].size() < abs(y)) {
				m_heightMap[abs(x)].resize(abs(y));
			}
			m_heightMap[abs(x)].emplace(m_heightMap[abs(x)].begin() + abs(y));
			if (m_heightMap[abs(x)][abs(y)].size() < abs(z)) {
				m_heightMap[abs(x)][abs(y)].resize(abs(z));
			}
			m_heightMap[abs(x)][abs(y)].emplace(m_heightMap[abs(x)][abs(y)].begin() + abs(z));

			std::tuple<int, int, int> coords = std::make_tuple(x, y, z);
			float height = m_heightGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0);
	 		std::pair<std::tuple<int, int, int>, float> heightPair = std::make_pair(coords, height);
			m_heightMap[abs(x)][abs(y)][abs(z)].push_back(heightPair);


			if (m_biomeMap[abs(x)].size() < abs(y)) {
				m_biomeMap[abs(x)].resize(abs(y));
			}

			m_biomeMap[abs(x)].emplace(m_biomeMap[abs(x)].begin() + abs(y));
			if (m_biomeMap[abs(x)][abs(y)].size() < abs(z)) {
				m_biomeMap[abs(x)][abs(y)].resize(abs(z));
			}
			m_biomeMap[abs(x)][abs(y)].emplace(m_biomeMap[abs(x)][abs(y)].begin() + abs(z));
			float biome = m_biomeGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0);
			std::pair<std::tuple<int, int, int>, float> biomePair = std::make_pair(coords, biome);
			m_biomeMap[abs(x)][abs(y)][abs(z)].push_back(biomePair);

			m_blocks[abs(x)].emplace(m_blocks[abs(x)].begin() + abs(y));
			if (m_blocks[abs(x)][abs(y)].size() < abs(z)) {
				m_blocks[abs(x)][abs(y)].resize(abs(z));
			}
			m_blocks[abs(x)][abs(y)].emplace(m_blocks[abs(x)][abs(y)].begin() + abs(z));
			// Sorts through the X, Y, and Z coordinate vector for the specific signed coordinate.
			int heightIndex = -1;
			for (int times = 0; times < m_heightMap[abs(x)][abs(y)][abs(z)].size(); times++) {
				if (std::get<0>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == x && std::get<1>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == y && std::get<2>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == z) {
					heightIndex = times;
				}
			}
			if (heightIndex == -1) {
				if (Utils::Math::inRange(Utils::BiomeConstraints::desertMin, Utils::BiomeConstraints::desertMax, m_heightMap[abs(x)][abs(y)][abs(z)].at(heightIndex).second)) {
					if (Utils::Math::inRange(Utils::BiomeBlockConstraints::desert::gravel::min, Utils::BiomeBlockConstraints::desert::gravel::max, m_blockGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0))) {
						m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::gravel, "\n"));
					}
					if (Utils::Math::inRange(Utils::BiomeBlockConstraints::desert::sand::min, Utils::BiomeBlockConstraints::desert::sand::max, m_blockGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0))) {
						m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::sand, "\n"));
					}
					printf("%s", m_blocks[abs(x)][abs(y)][abs(z)].at(0).block.name.c_str());
				}
			}
		}
	}
	else {
		// Happens if there is no X, Y, or Z coordinate
		// Generates height map for coordinate
		if (m_heightMap.size() < abs(x)) {
			m_heightMap.resize(abs(x));
		}
		m_heightMap.emplace(m_heightMap.begin() + abs(x));

		if (m_heightMap[abs(x)].size() < abs(y)) {
			m_heightMap[abs(x)].resize(abs(y));
		}
		m_heightMap[abs(x)].emplace(m_heightMap[abs(x)].begin() + abs(y));
		if (m_heightMap[abs(x)][abs(y)].size() < abs(z)) {
			m_heightMap[abs(x)][abs(y)].resize(abs(z));
		}
		m_heightMap[abs(x)][abs(y)].emplace(m_heightMap[abs(x)][abs(y)].begin() + abs(z));

		std::tuple<int, int, int> coords = std::make_tuple(x, y, z);
		float height = m_heightGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0);
 		std::pair<std::tuple<int, int, int>, float> heightPair = std::make_pair(coords, height);
		m_heightMap[abs(x)][abs(y)][abs(z)].push_back(heightPair);

		// Generates biome map for coordinate based off coordinate. A maybe
		if (m_biomeMap.size() < abs(x)) {
			m_biomeMap.resize(abs(x));
		}
		m_biomeMap.emplace(m_biomeMap.begin() + abs(x));

		if (m_biomeMap[abs(x)].size() < abs(y)) {
			m_biomeMap[abs(x)].resize(abs(y));
		}

		m_biomeMap[abs(x)].emplace(m_biomeMap[abs(x)].begin() + abs(y));
		if (m_biomeMap[abs(x)][abs(y)].size() < abs(z)) {
			m_biomeMap[abs(x)][abs(y)].resize(abs(z));
		}
		m_biomeMap[abs(x)][abs(y)].emplace(m_biomeMap[abs(x)][abs(y)].begin() + abs(z));
		float biome = m_biomeGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0);
		std::pair<std::tuple<int, int, int>, float> biomePair = std::make_pair(coords, biome);
		m_biomeMap[abs(x)][abs(y)][abs(z)].push_back(biomePair);

		// Generates block map based off height map and coordinate
		if (m_blocks.size() < abs(x)) {
			m_blocks.resize(abs(x));
		}
		m_blocks.emplace(m_blocks.begin() + abs(x));
		if (m_blocks[abs(x)].size() < abs(y)) {
			m_blocks[abs(x)].resize(abs(y));
		}
		m_blocks[abs(x)].emplace(m_blocks[abs(x)].begin() + abs(y));
		if (m_blocks[abs(x)][abs(y)].size() < abs(z)) {
			m_blocks[abs(x)][abs(y)].resize(abs(z));
		}
		m_blocks[abs(x)][abs(y)].emplace(m_blocks[abs(x)][abs(y)].begin() + abs(z));
		// Sorts through the X, Y, and Z coordinate vector for the specific signed coordinate.
		int heightIndex = -1;
		for (int times = 0; times < m_heightMap[abs(x)][abs(y)][abs(z)].size(); times++) {
			if (std::get<0>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == x && std::get<1>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == y && std::get<2>(m_heightMap[abs(x)][abs(y)][abs(z)].at(times).first) == z) {
				heightIndex = times;
			}
		}
		if (heightIndex == -1) {
			if (Utils::Math::inRange(Utils::BiomeConstraints::desertMin, Utils::BiomeConstraints::desertMax, m_heightMap[abs(x)][abs(y)][abs(z)].at(heightIndex).second)) {
				if (Utils::Math::inRange(Utils::BiomeBlockConstraints::desert::gravel::min, Utils::BiomeBlockConstraints::desert::gravel::max, m_blockGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0))) {
					m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::gravel, "\n"));
				}
				if (Utils::Math::inRange(Utils::BiomeBlockConstraints::desert::sand::min, Utils::BiomeBlockConstraints::desert::sand::max, m_blockGenerate.generate(x / 1000.0, y / 1000.0, z / 1000.0))) {
					m_blocks[abs(x)][abs(y)][abs(z)].push_back(BlockDataStruct(x, y, z, Blocks::sand, "\n"));
				}
				printf("%s", m_blocks[abs(x)][abs(y)][abs(z)].at(0).block.name.c_str());
			}
		}
	}
	return BlockDataStruct(1, 1, 1, Blocks::sand, "\n");
}
