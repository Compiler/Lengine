#include "OrthographicCamera.h"



OrthographicCamera::OrthographicCamera(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat far, GLfloat near)
{





	GLfloat scale[4][4] = { { 2 / (right - left), 0, 0, 0 },
							{ 0, 2 / (top - bottom), 0, 0 },
							{ 0, 0, 2 / (far - near), 0 },
							{ 0, 0, 0, 1 } };
	scaleMatrix.set(scale);

	GLfloat translation[4][4] = { {1, 0, 0, -((left + right) / 2) },
								  {0, 1, 0, -((top + bottom) / 2) },
								  {0, 0, -1, -((far + near) / 2) },
								  { 0, 0, 0, 1}};
	translationMatrix.set(translation);

	orthographicMatrix = (translationMatrix * scaleMatrix);

}

OrthographicCamera::OrthographicCamera() {}


void OrthographicCamera::init(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat far, GLfloat near) {

	GLfloat scale[4][4] = { { 2 / (right - left), 0, 0, 0 },
	{ 0, 2 / (top - bottom), 0, 0 },
	{ 0, 0, 2 / (far - near), 0 },
	{ 0, 0, 0, 1 } };
	scaleMatrix.set(scale);

	GLfloat translation[4][4] = { { 1, 0, 0, -((left + right) / 2) },
	{ 0, 1, 0, -((top + bottom) / 2) },
	{ 0, 0, -1, -((far + near) / 2) },
	{ 0, 0, 0, 1 } };
	translationMatrix.set(translation);

	orthographicMatrix = (translationMatrix * scaleMatrix);

}



void OrthographicCamera::translate(GLfloat xAmount, GLfloat yAmount, GLfloat zAmount) {
	translationMatrix.setElement(0, 3, xAmount);
	translationMatrix.setElement(1, 3, yAmount);
	translationMatrix.setElement(2, 3, zAmount);

	orthographicMatrix = (translationMatrix * scaleMatrix);
}

void OrthographicCamera::scale(GLfloat amount) {}
void OrthographicCamera::scale(GLfloat xAmount, GLfloat yAmount) {}
void OrthographicCamera::scaleX(GLfloat amount) {}
void OrthographicCamera::scaleY(GLfloat amount) {}


OrthographicCamera::~OrthographicCamera()
{
}
