#pragma once
#include "Vertex.h"
#include <GL\glew.h>


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



	void render();

	~Sprite();


private:

	VertexNorm vertex[4];
	
	

};

