#pragma once
#include <GL\glew.h>



struct Position {

	float x, y;

};


struct UV{

	float u, v;

};

struct Color {

	GLubyte r, g, b, a;
};



struct Vertex {

	//8 bits
	Position position;
	//4 bits
	Color color;
	//8 bits
	UV uv;
	//8+8+4 = 20 =   padding needed

	void setUV(float u, float v) {
		uv.u = u;
		uv.v = v;
	}

	void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}

	void setPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}
};