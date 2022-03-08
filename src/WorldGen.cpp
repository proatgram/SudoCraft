#include <cstdio>
#include <cstdint>

#include "../include/WorldGen.h"
#include "../include/PerlinNoise.hpp"

WorldGeneration::WorldGeneration(siv::PerlinNoise::seed_type seed) :
	m_seed(seed),
	m_noise(m_seed)
{

}

int WorldGeneration::getSeed() {
	return m_seed;
}

float WorldGeneration::generate(int x, int y) {
	return m_noise.noise2D(x * 0.01, y * 0.01);
}