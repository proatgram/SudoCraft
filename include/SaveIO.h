/*
 * SaveIO.h
 *
 *  Created on: Jun 27, 2022
 *      Author: thetimbrick
 */

#ifndef INCLUDE_SAVEIO_H_
#define INCLUDE_SAVEIO_H_

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <utility>
#include <cstring>
#include <algorithm>


class SaveIO {
	public:
		typedef std::stringstream Buffer;

		static const int FAIL;

		static const int SUCCESS;

		struct Filetypes {
			static const unsigned char SAVES_FILE;

			static const unsigned char PLAYERS_FILE;

			static const unsigned char PLAYER_DATA_FILE;

			static const unsigned char IMPORTANT_ENTITIES_FILE;

			static const unsigned char LEVEL_DATA_FILE;

			static const unsigned char MAINS_FILE;

			static const unsigned char CHUNK_FILE;
		};

		struct Sections {
			static const unsigned char HEADER;

			static const unsigned char NSET;

			static const unsigned char NSSET;
		};

		static int readFile(SaveIO::Buffer* buffer, std::filesystem::path path);

		static SaveIO::Buffer* readFile(std::filesystem::path path);
        
		static int readSet(SaveIO::Buffer* buffer, unsigned int setNumber, std::filesystem::path path);

        static int readHeader(SaveIO::Buffer* buffer, std::pair<unsigned char, double>& pair);

        static int readHeader(std::filesystem::path path, std::pair<unsigned char, double>& pair);

		static SaveIO::Buffer* readSet(unsigned int setNumber, std::filesystem::path path);
	private:

};



#endif /* INCLUDE_SAVEIO_H_ */
