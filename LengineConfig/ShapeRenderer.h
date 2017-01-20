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



	void drawRectangle();

	~ShapeRenderer();


private:

};

