#pragma once
#include <GL\glew.h>



struct Color{


	Color::Color(GLfloat rr, GLfloat gg, GLfloat bb, GLfloat aa){
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}
	GLfloat r, g, b, a;
	
	void set(GLfloat rr, GLfloat gg, GLfloat bb, GLfloat aa){
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}

	
};

Color RED(1.0f, 0.0f, 0.0f, 1.0f);
Color BLUE(0.0f, 0.0f, 1.0f, 1.0f);
Color GREEN(0.0f, 1.0f, 0.0f, 1.0f);
Color YELLOW(1.0f, 1.0f, 0.0f, 1.0f);

