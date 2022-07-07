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
	fileBuff.seekg(0, std::fstream::end);
    int size = fileBuff.tellg();
    fileBuff.seekg(0, std::fstream::beg);
    char* tempBuff = new char[size];
    fileBuff.read(tempBuff, size);
    file->write(tempBuff, size);
    file->seekg(0);
    fileBuff.close();
    delete[] tempBuff;
	return file;
}

int SaveIO::readSet(SaveIO::Buffer* buffer, unsigned int setNumber, std::filesystem::path path) {
    SaveIO::Buffer* buff = SaveIO::readFile(path);
    uint8_t* tempBuff = new uint8_t[std::numeric_limits<uint16_t>::max()];
    buff->seekg(13);
    unsigned int currentSet = 0;
    unsigned int setSize = 0;    
    while (currentSet < setNumber) {
        if (buff->get() != SaveIO::Sections::NSET) {
            std::printf("Flahsdkaail.\n");
            return SaveIO::FAIL;
        }
        buff->get((char*)tempBuff, 4);
        std::copy(tempBuff, &tempBuff[3], &setSize);
        buff->seekg(setSize + 1, SaveIO::Buffer::cur);
        currentSet++;
    }
    if (buff->get() != SaveIO::Sections::NSET) {
        std::printf("Fail.\n");
        return SaveIO::FAIL;
    } 
    buff->get((char*)tempBuff, 4);
    std::copy(tempBuff, &tempBuff[3], &setSize);
    buff->seekg(1, std::ios::cur);
    for (unsigned int i = 0; i < setSize; i++) {
        tempBuff[i] = buff->get();
    }
    buffer->write((char*)tempBuff, setSize);
    buffer->seekg(0, std::ios::end);
    delete buff;
    delete[] tempBuff;
    return SaveIO::SUCCESS;
}
 
SaveIO::Buffer* SaveIO::readSet(unsigned int setNumber, std::filesystem::path path) {
    SaveIO::Buffer* buffer = new SaveIO::Buffer;
    SaveIO::Buffer* buff = SaveIO::readFile(path);
    uint8_t* tempBuff = new uint8_t[std::numeric_limits<uint16_t>::max()];
    buff->seekg(13);
    unsigned int currentSet = 0;
    unsigned int setSize = 0;    
    while (currentSet < setNumber) {
        if (buff->get() != SaveIO::Sections::NSET) {
            std::printf("Flahsdkaail.\n");
            return nullptr;
        }
        buff->get((char*)tempBuff, 4);
        std::copy(tempBuff, &tempBuff[3], &setSize);
        buff->seekg(setSize + 1, SaveIO::Buffer::cur);
        currentSet++;
    }
    if (buff->get() != SaveIO::Sections::NSET) {
        std::printf("Fail.\n");
        return nullptr;
    } 
    buff->get((char*)tempBuff, 4);
    std::copy(tempBuff, &tempBuff[3], &setSize);
    buff->seekg(1, std::ios::cur);
    for (unsigned int i = 0; i < setSize; i++) {
        tempBuff[i] = buff->get();
    }
    buffer->write((char*)tempBuff, setSize);
    buffer->seekg(0, std::ios::end);
    delete buff;
    delete[] tempBuff;
    return buffer;
}
