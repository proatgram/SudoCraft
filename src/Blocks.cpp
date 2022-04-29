#include "Blocks.h"
BlockDataStruct::BlockDataStruct(signed long int X, signed long int Y, signed long int Z, BlockInfo Block, std::string NbtData) :
	x(X),
	y(Y),
	z(Z),
	block(Block),
	nbtData(NbtData)
{

}

void BlockDataStruct::nbtSet(std::string nbtData) {
	this->nbtData = nbtData;
}

void BlockDataStruct::nbtAppend(std::string nbtData) {
	this->nbtData.append(nbtData);
}

BlockInfo::BlockInfo(std::string Name, unsigned short int Id, std::string TextureTopPath) :
	name(Name),
	id(Id),
	textureTopPath(TextureTopPath)
{

}

BlockInfo Blocks::dirt = BlockInfo("Dirt", 0, "\n");
BlockInfo Blocks::grass = BlockInfo("Grass", 1, "\n");
BlockInfo Blocks::gravel = BlockInfo("Gravel", 2, "\n");
BlockInfo Blocks::sand = BlockInfo("Sand", 3, "\n");
BlockInfo Blocks::snow = BlockInfo("Snow", 4, "\n");
BlockInfo Blocks::softDirt = BlockInfo("Soft Dirt", 5, "\n");
BlockInfo Blocks::snowyGrass = BlockInfo("Snowy Grass", 6, "\n");
BlockInfo Blocks::water = BlockInfo("Water", 7, "\n");
BlockInfo Blocks::packedSnow = BlockInfo("Packed Snow", 8, "\n");
BlockInfo Blocks::packedIce = BlockInfo("Packed Ice", 9, "\n");
BlockInfo Blocks::ice = BlockInfo("Ice", 10, "\n");
BlockInfo Blocks::rock = BlockInfo("Rock", 11, "\n");
