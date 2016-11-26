#pragma once

#include <string>
#include <vector>

class IOManager
{
public:
	
	static bool loadFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
	static bool loadFileToString(std::string filePath, std::string& stringBuffer);

};

