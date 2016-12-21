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

	void set(color color) {
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}

};



struct Vertex {
	color color;
	lml::Vector2f position;

	template <typename T> void setPosition(T x, T y) {
		position.x = (GLfloat)x;
		position.y = (GLfloat)y;
	}

};
