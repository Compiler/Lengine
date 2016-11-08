#pragma once


#include <SDL\SDL.h>
#include <GL\glew.h>
#include "Vertex.h"
#include <lml\Vector2f.h>

class Sprite{
public:
	Sprite();


	void init(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void update();
	void render();
	void rotateBy();
	void translate(GLfloat x, GLfloat y);

	~Sprite();

private:
	Vertex vertex[6];
	GLfloat width, height;
	lml::Vector2f position;
	GLuint vbo;

};

