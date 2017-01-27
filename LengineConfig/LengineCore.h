#pragma once

#include <iostream>
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "OrthographicCamera.h"
#include "ShapeRenderer.h"
#include "Sprite.h"
class LengineCore
{
public:
	LengineCore();

	void run();

	GLfloat deltaTime;

	~LengineCore();


private:


	void init();
	void update();
	void render();

	ShapeRenderer rend;
	OrthographicCamera cam;

	Sprite sprite;
};

