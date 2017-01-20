#pragma once
#include <GL\glew.h>

enum ShapeType{
	LINE,
	FILLED
};

class ShapeRenderer{
public:
	ShapeRenderer();
	ShapeRenderer(ShapeType type);



	void drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height);

	~ShapeRenderer();


private:

};

