#pragma once
#include <GL\glew.h>

struct Vertex {

	//8 bits
	Position position;
	//4 bits
	Color color;
	//8 bits
	UV uv;
	//8+8+4 = 20 =   padding needed

};


struct Position {

	float x, y;

	void set(float newX, float newY) {
		x = newX;
		y = newY;
	}
};


struct UV{

	float u, v;

	void set(float newU, float newV) {
		u = newU;
		v = newV;
	}
}uv;

struct Color {

	GLubyte r, g, b, a;

	void set(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}
};