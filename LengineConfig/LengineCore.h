#pragma once

#include <iostream>
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "IOManager.h"

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


	IOManager manager;
	GLuint vertexID, bufferID;
};

