#include "OrthographicCamera.h"
#include <iostream>


OrthographicCamera::OrthographicCamera(GLfloat width, GLfloat height)
{

	GLfloat ortho[4][4] =
	{ { 2.0f / width, 0, 0, -1 },
	{ 0, 2.0f / height, 0, -1 },
	{ 0, 0, -1, 0 },
	{ 0, 0, 0, 1 } };

	orthographicMatrix.set(ortho);


}

OrthographicCamera::OrthographicCamera() {}


void OrthographicCamera::init(GLfloat width, GLfloat height) {

	GLfloat ortho[4][4] =
	{ { 2.0f / width, 0, 0, -(width + 0) / (width - 0) },
	{ 0, 2.0f / height, 0, -1 },
	{ 0, 0, 2.0f / (-1 - 1), 0 },
	{ 0, 0, 0, 1 } };

	orthographicMatrix.set(ortho);
	
}



void OrthographicCamera::translate(GLfloat xAmount, GLfloat yAmount, GLfloat zAmount) {
	
	
	//orthographicMatrix.print();
}

void OrthographicCamera::scale(GLfloat amount) {}
void OrthographicCamera::scale(GLfloat xAmount, GLfloat yAmount) {}
void OrthographicCamera::scaleX(GLfloat amount) {}
void OrthographicCamera::scaleY(GLfloat amount) {}


OrthographicCamera::~OrthographicCamera()
{
}
