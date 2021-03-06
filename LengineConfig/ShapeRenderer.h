#pragma once
#include <GL\glew.h>
#include "Vertex.h"
#include "ShaderProgram.h"
#include <vector>

enum ShapeType{
	LINE,
	FILLED
};


class ShapeRenderer{
public:
	ShapeRenderer();
	ShapeRenderer(ShapeType type);


	void init();

	void begin();
	void end();
	void drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height);
	void drawTriangle(GLfloat xPos1, GLfloat yPos1, GLfloat xPos2, GLfloat yPos2, GLfloat xPos3, GLfloat yPos3);
	void setColor(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);


	Color getColor(){ return color; }

	GLuint getShaderID(){ return shader.getProgramID(); }
	~ShapeRenderer();


private:

	ShapeType type;
	Color color;

	GLuint vertexID, bufferID;

	GLuint count;
	std::vector<Vertex> vertices;

	ShaderProgram shader;
};

