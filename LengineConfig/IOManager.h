#pragma once

#include <string>

class IOManager
{
public:
	IOManager();

	static void readToString(std::string filePath, std::string &input);
	void readToChar(std::string filePath, char* &mine);
	~IOManager();
};

