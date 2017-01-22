#pragma once
#include <GL\glew.h>
#include "Color.h"

enum ShapeType{
	LINE,
	FILLED
};

class ShapeRenderer{
public:
	ShapeRenderer();
	ShapeRenderer(ShapeType type);


	void begin();
	void end();
	void drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height);

	~ShapeRenderer();


private:

	ShapeType type;
	Color color = LIGHT_GRAY;

};

