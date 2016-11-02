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
	void bindAttrib();
	GLint getUniformLocation();

	~ShaderProgram();

private:

	void compileShader(std::string filePath, GLuint shaderID);


	GLuint programID, vertexID, fragmentID;

};

