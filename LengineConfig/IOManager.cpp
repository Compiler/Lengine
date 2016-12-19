#include "IOManager.h"
#include <fstream>
#include <iostream>

IOManager::IOManager()
{
}


void IOManager::readToString(std::string filePath, std::string &input) {
	std::ifstream file(filePath);
	if (file.fail()) {
		std::cout << "File: " << filePath << " -- Failed to open\n";
	}
	char temp;
	while (file.get(temp)) {
		input += temp;
	}

	
}
void IOManager::readToChar(std::string filePath, char* &mine) {
	
	std::ifstream file(filePath);
	if (file.fail()) {
		std::cout << "File: " << filePath << " -- Failed to open\n";
	}
	char temp;
	while (file.get(temp)) {
		*mine += temp;
	}

}


IOManager::~IOManager()
{
}
