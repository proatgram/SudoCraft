/*
 * SaveIO.cpp
 *
 *  Created on: Jun 27, 2022
 *      Author: thetimbrick
 */

#include "SaveIO.h"

const int SaveIO::FAIL = 1;

const int SaveIO::SUCCESS = 0;

const unsigned char SaveIO::Sections::HEADER = 1;

const unsigned char SaveIO::Sections::NSET = 2;

const unsigned char SaveIO::Sections::NSSET = 3;

const unsigned char SaveIO::Filetypes::CHUNK_FILE = 7;

const unsigned char SaveIO::Filetypes::IMPORTANT_ENTITIES_FILE = 3;

const unsigned char SaveIO::Filetypes::LEVEL_DATA_FILE = 4;

const unsigned char SaveIO::Filetypes::MAINS_FILE = 5;

const unsigned char SaveIO::Filetypes::PLAYERS_FILE = 1;

const unsigned char SaveIO::Filetypes::SAVES_FILE = 0;

int SaveIO::readFile(SaveIO::Buffer* buffer, std::filesystem::path path) {
	std::fstream fileBuff(std::filesystem::absolute(path).string(), std::fstream::in | std::fstream::out | std::fstream::binary);
	if (!fileBuff) {
		return SaveIO::FAIL;
	}

	*buffer << fileBuff.rdbuf();
	fileBuff.close();
	return SaveIO::SUCCESS;
}

SaveIO::Buffer* SaveIO::readFile(std::filesystem::path path) {
	SaveIO::Buffer* file = new SaveIO::Buffer();
	std::fstream fileBuff(std::filesystem::absolute(path).string(), std::fstream::in | std::fstream::out | std::fstream::binary);
	if (!fileBuff) {
		return nullptr;
	}

	*file << fileBuff.rdbuf();
	return file;
}

int SaveIO::readSet(SaveIO::Buffer* buffer, unsigned int setNumber, std::filesystem::path path) {
	std::fstream fileBuff(std::filesystem::absolute(path).string(), std::fstream::in | std::fstream::out | std::fstream::binary);
	if (!fileBuff) {
		std::printf("fail");
		return SaveIO::FAIL;
	}
	unsigned int pos = 0;
	fileBuff.seekg(std::fstream::end);
	unsigned int end = fileBuff.tellg();
	fileBuff.seekg(std::fstream::beg);
	if (fileBuff.get() != SaveIO::Sections::HEADER) {
		return SaveIO::FAIL;
	}
	fileBuff.seekg(2, std::fstream::cur);
	union bytes {
		unsigned char byte[8];
		double doub;
		uint32_t uin32;
	}myb;
	for (unsigned int times = 0; times < 8; times++) {
		myb.byte[times] = fileBuff.get();
	}
	while (pos != setNumber) {
		if (fileBuff.get() != SaveIO::Sections::NSET) {
			return SaveIO::FAIL;
		}

		for (unsigned int times = 0; times < 4; times++) {
			myb.byte[times] = fileBuff.get();
		}
		fileBuff.seekg(myb.uin32, std::fstream::cur);
		pos++;

	}
	if (fileBuff.get() != SaveIO::Sections::NSET) {
		return SaveIO::FAIL;
	}
	for (unsigned int times = 0; times < 4; times++) {
		myb.byte[times] = fileBuff.get();
	}
	for (unsigned int times = 0; times < myb.uin32; times++) {
		*buffer << (char)fileBuff.get();
	}

	fileBuff.close();
	return SaveIO::SUCCESS;
}
