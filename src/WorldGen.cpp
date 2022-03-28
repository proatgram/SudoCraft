#include <cstdio>
#include <cstdint>

#include "noise/noise.h"
#include "WorldGen.h"

WorldGeneration::WorldGeneration(int seed)
{
	m_perlinNoise.SetSeed(seed);
}

int WorldGeneration::getSeed() {	
	return m_perlinNoise.GetSeed();
}

float WorldGeneration::generate(double x, double y, double z) {
	return m_perlinNoise.GetValue(x, y, z);
}
