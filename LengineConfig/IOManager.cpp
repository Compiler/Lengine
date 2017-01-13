#include "IOManager.h"
#include <fstream>
#include <iostream>

IOManager::IOManager()
{
}












void IOManager::read(const char *filePath, std::string &info) {

	std::fstream file;
	file.open(filePath);

	if (file.fail()) {
		std::cout << "Couldn't open: \"" << filePath << "\"\n";
		return;
	}

	std::vector<GLchar> vec;
	if (!file.eof() && !file.fail())
	{
		file.seekg(0, std::ios_base::end);
		std::streampos fileSize = file.tellg();


		vec.resize(fileSize);

		file.seekg(0, std::ios_base::beg);
		file.read(&vec[0], fileSize);
		info = "";
		for(int i = 0; i < vec.size(); i++)
			info += vec[i];

	}
}


//takes info and loads it to the buffer given by reference
void IOManager::readFileToBuffer(std::string &filePath, std::vector<unsigned char>& buffer) {

	//read in binary 
	std::ifstream file(filePath, std::ios::binary);

	if (file.fail()) {
		perror(filePath.c_str());
	}

	//go to end of file, offest 0 bytes from end of file
	file.seekg(0, std::ios::end);

	//get size, tellg returns how many bytes we have gone through,
	//we started at the end so it gives us the full size ya dumb ass
	int fileSize = file.tellg();

	//seek to the beginning
	file.seekg(0, std::ios::beg);

	//for safety, get rid of header
	fileSize -= file.tellg();

	//resize our buffer to the filesize
	buffer.resize(fileSize);

	file.read((char *)&(buffer[0]), fileSize);

	file.close();

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
		info[fileSize] = '\0';
	}

}



void IOManager::read(const char *filePath, std::vector<GLchar> &vec) {
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
