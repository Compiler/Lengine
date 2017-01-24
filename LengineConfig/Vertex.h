#pragma once
#include <GL\glew.h>
#include <lml\Vector3.h>

struct Color{

	GLubyte red;
	GLubyte green;
	GLubyte blue;
	GLubyte alpha;

};



struct Position{
	Vector3 pos;
};


struct Vertex{


	Position position;
	Color color;

	void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
		color.red = r;
		color.green = g;
		color.blue = b;
		color.alpha = a;
	}

	void setPosition(GLfloat positionX, GLfloat positionY){
		position.pos.x = positionX;
		position.pos.y = positionY;
	}


};