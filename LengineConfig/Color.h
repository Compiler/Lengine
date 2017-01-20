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

Color LIGHT_GRAY(0.75f, 0.75f, 0.75f, 1.0f);
Color GRAY(0.50f, 0.5f, 0.5f, 1.0f);
Color DARK_GRAY(0.25f, 0.25f, 0.25f, 1.0f);

Color WHITE(1.0f, 1.0f, 1.0f, 1.0f);
Color BLACK(0.0f, 0.0f, 0.0f, 1.0f);


