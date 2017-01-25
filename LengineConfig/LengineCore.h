#pragma once

#include <iostream>
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "ShaderProgram.h"
#include "OrthographicCamera.h"
#include "ShapeRenderer.h"
#include "Sprite.h"
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

	ShapeRenderer rend;
	ShaderProgram shader;
	OrthographicCamera cam;


	Sprite sprite;

	GLuint vertexID, bufferID;
};

