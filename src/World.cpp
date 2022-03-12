#include <cmath>

#include "World.h"

World::World(int size_x, int size_y, int size_z, int seed) :
	m_size_x(size_x),
	m_size_y(size_y),
	m_size_z(size_z),
	m_generate(seed)

{

}

World::BlockDataStruct World::getBlock(int x, int y, int z) {
	signed char coord = 0;
	if (x < 0) {
		coord | 0b00000001;
	}
	if (y < 0) {
		coord | 0b00000010;
	}
	if (z < 0) {
		coord | 0b00000100;
	}
	/*
	if (m_blocks.size() >= abs(x)) {
		if (m_blocks.at(abs(x)).size() >= abs(y)) {
			if (m_blocks.at(abs(x)).at(abs(y)).size() >= abs(z)) {
				for (unsigned char times = 0; times < m_blocks.at(abs(x)).at(abs(y)).size(); times++) {
					m_blocks.
				}
			}
		}
	}
	*/
}