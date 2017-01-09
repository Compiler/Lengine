#pragma once

#include <iostream>
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "ShaderProgram.h"

class LengineCore
{
public:
	LengineCore();



	void run();


	~LengineCore();


private:


	void init();
	void update();
	void render();


	ShaderProgram shader;
	GLuint vertexID, bufferID;
};

