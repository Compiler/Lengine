#pragma once
#include <GL/glew.h>
#include "mat4.h"


class OrthographicCamera
{
public:
	OrthographicCamera();
	OrthographicCamera(GLfloat width, GLfloat height);

	void init(GLfloat width, GLfloat height);
	void translate(float x, float y);
	void flip(bool x, bool y);
	void rotateAbout(float x, float y, float degrees);
	GLfloat* getUniformVal();

	~OrthographicCamera();

private:

	GLfloat width, height;

	mat4 matrix;

};

