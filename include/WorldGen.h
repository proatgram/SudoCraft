#include <cstdio>
#include <cstdint>

#include "noise/noise.h"

#ifndef __WORLD_GEN_H__
#define __WORLD_GEN_H__

class WorldGeneration {
public:
	WorldGeneration(int seed);

	int getSeed();
	float generate(double x, double y, double z);
private:
	noise::module::Perlin m_perlinNoise;
};

#endif
