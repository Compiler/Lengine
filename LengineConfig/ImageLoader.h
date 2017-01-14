#pragma once


#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <GL\glew.h>
#include <vector>


void LoadBMP(const char * fileName, unsigned long &width, unsigned long &height, GLuint &texture){

	
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
	unsigned char *pixels = new unsigned char[width*height * 3];
	file.seekg(headerOffset + 40);
	file.read((char *)pixels, width*height*3);

	unsigned char tmpRGB = 0; // Swap buffer
	for (unsigned long i = 0; i < width * height * 3; i += 3)
	{
		tmpRGB = pixels[i];
		pixels[i] = pixels[i + 2];
		pixels[i + 2] = tmpRGB;
	}

	glGenTextures(1, &texture);             // Generate a texture
	glBindTexture(GL_TEXTURE_2D, texture); // Bind that texture temporarily

	GLint mode = GL_RGB;                   // Set the mode

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, mode, width, height, 0, mode, GL_UNSIGNED_BYTE, pixels);


	delete[] pixels;
	delete[] data;
	file.close();
	std::cout << "\n\n\n";

}