#pragma once
#include <string>
#include <GL\glew.h>
#include "IOManager.h"

class ShaderProgram
{
public:
	ShaderProgram();

	void create(const GLchar *vertexFilePath, const GLchar *fragFilePath);

	~ShaderProgram();


private:

	IOManager manager;

	
};

