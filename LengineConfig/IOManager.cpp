#include "IOManager.h"
#include <fstream>
#include <iostream>

IOManager::IOManager()
{
}

/*
	Users responsablility to allocate enough memory
*/
void IOManager::read(const char *filePath, char *info) {

	std::fstream file;
	file.open(filePath);

	if (file.fail()) {
		std::cout << "Couldn't open: \"" << filePath << "\"\n";
		return;
	}
	

	if (!file.eof() && !file.fail())
	{
		file.seekg(0, std::ios_base::end);
		std::streampos fileSize = file.tellg();
		

		file.seekg(0, std::ios_base::beg);
		file.read(info, fileSize);
		std::cout << fileSize;
		info[fileSize] = '\0';
	}

}



void IOManager::read(const char *filePath, std::vector<char> &vec) {
	std::fstream file;
	file.open(filePath);

	if (file.fail()) {
		std::cout << "Couldn't open: \"" << filePath << "\"\n";
		return;
	}



	if (!file.eof() && !file.fail())
	{
		file.seekg(0, std::ios_base::end);
		std::streampos fileSize = file.tellg();
		vec.resize(fileSize);

		file.seekg(0, std::ios_base::beg);
		file.read(&vec[0], fileSize);
	}

}
IOManager::~IOManager()
{
}
