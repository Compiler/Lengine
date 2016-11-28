#pragma once


#include <SDL\SDL.h>
#include <GL\glew.h>
#include "Vertex.h"
#include <lml\Vector2f.h>
#include "GLTexture.h"

class Sprite{
public:
	Sprite();


	void init(std::string filePath, GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void update();
	void render();
	void rotateBy();
	void translate(GLfloat x, GLfloat y);

	GLint getTextureID();

	~Sprite();

private:
	Vertex vertex[6];
	GLfloat width, height;
	lml::Vector2f position;
	GLuint vbo;
	GLTexture texture;
};

