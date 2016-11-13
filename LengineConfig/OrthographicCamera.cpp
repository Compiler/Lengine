#include "OrthographicCamera.h"
#include <iostream>
#include <SDL\SDL.h>

OrthographicCamera::OrthographicCamera(): zoom(1.0f)
{
	

}

OrthographicCamera::OrthographicCamera(GLfloat width, GLfloat height): width(width), height(height), zoom(1)
{
	position.set(0.0f, 0.0f);
	
	GLfloat first[16] = { 
		zoom * 2.0f / width, 0.0f, 0.0f, 0.0f,
		0.0f, zoom * 2.0f / height, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
	matrix.initByArray(first);
	

}

/*
	Initializes the camera with the given viewport dimensions and 
	is defaulted to be set at 0,0,0
*/
void OrthographicCamera::init(GLfloat width, GLfloat height) {
	zoom = 1.0f;
	viewport.set(width, height);
	GLfloat first[16] = {
		zoom * 2.0f / width, 0.0f, 0.0f, 0.0f,
		0.0f, zoom * 2.0f / height, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
	matrix.initByArray(first);

	std::cout << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++)
			std::cout << matrix.getElement(k, i) << ",";
		std::cout << std::endl;

		//matrix.setElement(1, 1, 1.0f);
	}

}

/*
	Initializes the camera with the given viewport dimensions and
	is also set to the given position to look at
*/
void OrthographicCamera::init(GLfloat posX, GLfloat posY, GLfloat width, GLfloat height) {
	zoom = 1.0f;
	viewport.set(width, height);
	position.set(posX, posY);
	GLfloat first[16] = {
		zoom * 2.0f / (width - posX), 0.0f, 0.0f, 0.0f,
		0.0f, zoom * 2.0f / (height - posY), 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
	matrix.initByArray(first);

	std::cout << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++)
			std::cout << matrix.getElement(k, i) << ",";
		std::cout << std::endl;

		//matrix.setElement(1, 1, 1.0f);
	}

}

/*

	Translates the invoked camera by each vector component

*/
void OrthographicCamera::translate(float x, float y, float z) {

}
/*

	Deprecated

*/
void OrthographicCamera::translate(float x, float y) {
	float newX = matrix.getElement(0, 0) * x + matrix.getElement(1, 0) * y;
	float newY = matrix.getElement(0, 1) * x + matrix.getElement(1, 1) * y;
	matrix.setElement(3, 0, newX);
	matrix.setElement(3, 1, newY);
}

/*

	Scales the invoked camera

*/
void OrthographicCamera::scale(float x, float y) {
	matrix.translateElement(0, 0, x);
	matrix.translateElement(1, 1, y);
}
/*

	Flips the given camera over the given axis in boolean form

*/
void OrthographicCamera::flip(bool x, bool y) {

}

/*

	Rotates the looked at position of the camera about a given point
	by a given amount of degrees

*/

void OrthographicCamera::rotateAbout(float x, float y, float degrees) {

}


/*

	Returns the value able to be passed through OpenGL to
	GLSL to use as a uniform variable

*/

GLfloat* OrthographicCamera::getUniformVal() {
	
	return matrix.getLinear();
}

void getUniformVal(GLfloat(&arr)[16]) {
	
}

OrthographicCamera::~OrthographicCamera()
{
}
