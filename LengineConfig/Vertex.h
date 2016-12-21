#pragma once
#include <GL\glew.h>
#include <lml\Vector2f.h>

struct color {
	GLfloat r, g, b, a;
	void set(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}
};



struct Vertex {
	color color;
	lml::Vector2f position;
};
