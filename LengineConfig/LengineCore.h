#pragma once

#include <iostream>
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "ShaderProgram.h"
#include "OrthographicCamera.h"

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
	OrthographicCamera cam;
	GLuint vertexID, bufferID;
};

