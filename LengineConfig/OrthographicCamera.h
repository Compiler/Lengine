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
	void translate(float x, float y, float z);
	void flip(bool x, bool y);

	void scale(float x, float y);
	void rotateAbout(float x, float y, float degrees);
	GLfloat* getUniformVal();
	void getUniformVal(GLfloat (&arr)[16]);
	~OrthographicCamera();

private:

	GLfloat width, height;

	mat4 matrix;

};

