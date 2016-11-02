#pragma once


#include <SDL\SDL.h>
#include <GL\glew.h>


class Sprite{
public:
	Sprite();


	void init(float x, float y, float width, float height);
	void update();
	void render();

	~Sprite();

private:
	
	float x, y, width, height;
	GLuint vbo;

};

