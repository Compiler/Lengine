#include "OrthographicCamera.h"



OrthographicCamera::OrthographicCamera() {

}

OrthographicCamera::OrthographicCamera(GLfloat width, GLfloat height): width(width), height(height)
{

	
	GLfloat first[16] = { 
		2.0f / width, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f / height, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
	matrix.initByArray(first);
	

}


void OrthographicCamera::init(GLfloat width, GLfloat height) {
	GLfloat first[16] = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
	matrix.initByArray(first);

}

void OrthographicCamera::translate(float x, float y) {

}

void OrthographicCamera::flip(bool x, bool y) {

}

void OrthographicCamera::rotateAbout(float x, float y, float degrees) {

}

GLfloat* OrthographicCamera::getUniformVal() {
	return matrix.getLinear();
}

OrthographicCamera::~OrthographicCamera()
{
}
