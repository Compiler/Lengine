#pragma once

#include <GL\glew.h>

class OrthographicCamera{
public:
	
	OrthographicCamera(GLfloat width, GLfloat height);
	OrthographicCamera(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom);

	void init(GLfloat width, GLfloat height);
	void init(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom);



	~OrthographicCamera();

private:

	GLfloat left, right, top, bottom;
	GLfloat matrix[16] = {};
};

