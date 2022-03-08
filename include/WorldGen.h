#include <cstdio>
#include <cstdint>

#ifndef __WORLD_GEN__
#define __WORLD_GEN__

class WorldGeneration {
public:
	WorldGeneration();

	int getSeed();
	float generate(int x, int y);
private:

};

#endif
