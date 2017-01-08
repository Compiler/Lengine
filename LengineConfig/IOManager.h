#pragma once
#include <vector>


class IOManager
{
public:
	IOManager();


	void read(const char *filePath, char *info);
	void read(const char *filePath, std::vector<char> &vec);

	~IOManager();
};

