#include <string>

#ifndef __BLOCKS_H__
#define __BLOCKS_H__

struct BlockInfo {
	BlockInfo(std::string Name, unsigned short int Id, std::string TextureTopPath);
	std::string name;
	unsigned short int id;
	std::string textureTopPath;
};

struct BlockDataStruct {
	BlockDataStruct(signed long int X, signed long int Y, signed long int Z, BlockInfo Block, std::string NbtData);
	signed long int x;
	signed long int y;
	signed long int z;
	BlockInfo block;
	std::string nbtData;

	void nbtAppend(std::string nbtData);

	void nbtSet(std::string nbtData);
};
struct Blocks {
		static BlockInfo grass;
		static BlockInfo dirt;
		static BlockInfo sand;
		static BlockInfo gravel;
		static BlockInfo softDirt;
		static BlockInfo snow;
		static BlockInfo snowyGrass;
		static BlockInfo water;
		static BlockInfo packedSnow;
		static BlockInfo ice;
		static BlockInfo packedIce;
		static BlockInfo rock;
};


#endif
