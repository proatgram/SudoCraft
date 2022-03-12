#include <cstdio>
#include <cstdint>

#include "noise/noise.h"

#ifndef __WORLD_GEN__
#define __WORLD_GEN__

class WorldGeneration {
public:
	WorldGeneration(int seed);

	int getSeed();
	float generate(int x, int y, int z);
private:
	noise::module::Perlin m_perlinNoise;
};

#endif
