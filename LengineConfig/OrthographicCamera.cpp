#include "OrthographicCamera.h"
#include <iostream>


OrthographicCamera::OrthographicCamera(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat far, GLfloat near)
{




}

OrthographicCamera::OrthographicCamera() {}


void OrthographicCamera::init(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat far, GLfloat near) {

	



}



void OrthographicCamera::translate(GLfloat xAmount, GLfloat yAmount, GLfloat zAmount) {
	
	
	orthographicMatrix.print();
}

void OrthographicCamera::scale(GLfloat amount) {}
void OrthographicCamera::scale(GLfloat xAmount, GLfloat yAmount) {}
void OrthographicCamera::scaleX(GLfloat amount) {}
void OrthographicCamera::scaleY(GLfloat amount) {}


OrthographicCamera::~OrthographicCamera()
{
}
