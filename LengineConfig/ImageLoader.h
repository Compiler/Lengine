#pragma once


#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <GL\glew.h>
#include <vector>


void LoadBMP(const char * fileName, std::vector<unsigned char> &buffer, unsigned long &width, unsigned long &height){


	std::fstream file;
	file.open(fileName, std::fstream::binary | std::fstream::in);

	if (file.fail()) std::cout << "Couldn't open: `" << fileName << "`\n";
	GLchar * data;

	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);

	data = new GLchar[length];


	file.read(data, length);


	if(file)
		std::cout << "all characters read successfully.\n";
	else
		std::cout << "error: only " << file.gcount() << " could be read";

	GLchar sec = data[1];
	
	std::cout << data[0] << data[1] << "= ";

	switch (sec) {
	case 'M':std::cout << "Windows 3.1x"; break;
	case 'A':std::cout << "OS/2 struct bitmap array"; break;
	case 'I':std::cout << "OS/2 struct color icon"; break;
	case 'P':std::cout << "OS/2 const color pointer"; break;
	case 'C':std::cout << "OS/2 struct icon"; break;
	}

	int headerOffset = 50;

	width = *(GLuint *)&data[18];
	height = *(GLuint *)&data[22];

	int bpp = *(int *)&data[28];

	int compressionMethod = *(int *)&data[30];

	std::cout << "\nDimensions: " << width << "x" << height << "\n";
	std::cout << "Bits per pixel: " << bpp;
	std::cout << "\nCompression Method: " << compressionMethod << "\n";
	//start of pixel array - 50
	unsigned char *pixels = new unsigned char[length - headerOffset];
	file.seekg(headerOffset);
	file.read((char *)pixels, length - headerOffset);

	buffer.resize(length - headerOffset + 1);
	for (int i = 0; i < length - headerOffset; i++)
		buffer[i] = pixels[i];
	buffer[length - headerOffset + 1] = '\0';

	delete[] pixels;
	delete[] data;
	file.close();
	std::cout << "\n\n\n";

}