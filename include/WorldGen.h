#include <cstdio>
#include <cstdint>

#include "../include/PerlinNoise.hpp"

#ifndef __WORLD_GEN__
#define __WORLD_GEN__

class WorldGeneration {
	WorldGeneration(siv::PerlinNoise::seed_type seed);
public:
	int getSeed();
	float generate(int x, int y);
private:
	const siv::PerlinNoise::seed_type m_seed;
	const siv::PerlinNoise m_noise;

};

#endif
