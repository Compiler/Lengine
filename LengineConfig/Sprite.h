#pragma once

#include "Vertex.h"
#include "ShaderProgram.h"

#include <GL\glew.h>

#include "ImageLoader.h"

#include "OrthographicCamera.h"

enum PositionTuples{
	BOTTOM_LEFT,
	BOTTOM_RIGHT,
	TOP_LEFT,
	TOP_RIGHT
};

class Sprite{
public:
	
	
	
	Sprite();
	Sprite(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height, const char* filePath);
	
	void init(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height, const char* filePath);

	GLuint getShader(){ return shader.getProgramID(); }

	void render(const OrthographicCamera &camera);

	~Sprite();


private:

	VertexNorm vertex[4];

	GLuint width, height;

	GLuint vertexID;
	GLuint bufferID;
	GLuint eboID;

	GLuint indices[4];
	
	ShaderProgram shader;

	GLuint textureID;

};

