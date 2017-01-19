#include "OrthographicCamera.h"


#include <iostream>




OrthographicCamera::OrthographicCamera(): left(0), right(640), top(480), bottom(0){
	update();
}

OrthographicCamera::OrthographicCamera(GLfloat width, GLfloat height): left(0), right(width), top(height), bottom(0){
	

	update();

}

OrthographicCamera::OrthographicCamera(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom){
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
	update();
}


void OrthographicCamera::init(GLfloat width, GLfloat height){
	left = 0;
	bottom = 0;

	right = width;
	height = height;

	update();
}

void OrthographicCamera::init(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom){
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
	update();
}



void OrthographicCamera::update(){
	

	if(_update){
	
		matrix[0] = 2 / (right - left);
		matrix[3] = -(right + left) / (right - left);

		matrix[4] = 2 / (top - bottom);
		matrix[7] = -(top + bottom) / (top - bottom);

		_update = false;
	}

}


void OrthographicCamera::sendToShader(const GLuint &programID) const{
	glUniformMatrix4fv(programID, 1, GL_TRUE, matrix);
}

OrthographicCamera::~OrthographicCamera(){

}
