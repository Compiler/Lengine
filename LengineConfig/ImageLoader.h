#pragma once


#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <GL\glew.h>


void LoadBMP(const char * fileName){


	std::fstream file;
	file.open(fileName, std::fstream::binary | std::fstream::in);

	if (file.fail()) std::cout << "Couldn't open: `" << fileName << "`\n";
	char * data;

	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);

	data = new char[length];

	file.read(data, length);


	if(file)
		std::cout << "all characters read successfully.\n";
	else
		std::cout << "error: only " << file.gcount() << " could be read";

	char sec = data[1];
	
	std::cout << data[0] << data[1] << "= ";

	switch (sec) {
	case 'M':std::cout << "Windows 3.1x"; break;
	case 'A':std::cout << "OS/2 struct bitmap array"; break;
	case 'I':std::cout << "OS/2 struct color icon"; break;
	case 'P':std::cout << "OS/2 const color pointer"; break;
	case 'C':std::cout << "OS/2 struct icon"; break;
	}

	delete[] data;
	file.close();
	std::cout << "\n\n\n";

}