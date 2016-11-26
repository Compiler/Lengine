#include "IOManager.h"
#include <fstream>




bool IOManager::loadFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer) {
	
	std::ifstream file(filePath, std::ios::binary);

	if (file.fail()) {
		perror(filePath.c_str());
		return false;
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

	return true;

}


bool IOManager::loadFileToString(std::string filePath, std::string& stringBuffer) {
	std::vector<unsigned char> tmp;
	if (!(IOManager::loadFileToBuffer(filePath, tmp))) {
		return false;
	}
	
	for (int i = 0; i < tmp.size(); i++)
		stringBuffer += tmp[i];


	return true;
}
