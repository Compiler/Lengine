#pragma once
#include <GL\glew.h>
#include "Color.h"

#include <vector>

enum ShapeType{
	LINE,
	FILLED
};


struct Vertex{

	Vertex(GLfloat xPos, GLfloat yPos, Color col){
		x = xPos;
		y = yPos;
		color = col;
	}

	GLfloat x, y;
	Color color = WHITE;
	
};

class ShapeRenderer{
public:
	ShapeRenderer();
	ShapeRenderer(ShapeType type);


	void begin();
	void end();
	void drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height);
	void drawTriangle(GLfloat xPos1, GLfloat yPos1, GLfloat xPos2, GLfloat yPos2, GLfloat xPos3, GLfloat yPos3);
	~ShapeRenderer();


private:

	ShapeType type;
	Color color = LIGHT_GRAY;

	GLuint vertexID, bufferID;

	GLuint count;
	std::vector<GLfloat> vertices;

};

