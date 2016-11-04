#pragma once
#include <iostream>
#include <fstream>
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <string>
#include <vector>
#include "Error.h"

class ShaderProgram
{
public:
	ShaderProgram();



	void compile(std::string vertex, std::string fragment);
	void linkShaders();
	void bindAttrib(const std::string& attributeName, GLuint indexOfAttribute);
	void use();
	void unuse();
	GLint getUniformLocation(std::string name);

	~ShaderProgram();

private:

	void compileShader(std::string filePath, GLuint shaderID);

	int numOfAttribs;
	GLuint programID, vertexID, fragmentID;

};

