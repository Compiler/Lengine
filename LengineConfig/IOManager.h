#pragma once
#include <vector>
#include <GL\glew.h>
#include <string>

class IOManager
{
public:
	IOManager();


	void read(const char *filePath, std::string &info);
	void read(const char *filePath, char *info);
	void read(const char *filePath, std::vector<GLchar> &vec);

	~IOManager();
};

