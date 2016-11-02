#pragma once
#include <GL\glew.h>



struct Position {

	float x, y, z;

};


struct UV {

	float u, v;

};

struct Color {

	GLubyte r, g, b, a;
};



struct ModelVertex {


	Position position;

	Color color;

	UV uv;

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

	void setPosition(float x, float y, float z) {
		position.x = x;
		position.y = y;
		position.z = z;
	}
};