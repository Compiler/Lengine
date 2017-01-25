#include "OrthographicCamera.h"





OrthographicCamera::OrthographicCamera(): left(0), right(640), top(480), bottom(0){
	_update = true;
	matrix[10] = -1.0f;
	matrix[15] = 1.0f;
	update();
}

OrthographicCamera::OrthographicCamera(GLfloat width, GLfloat height): left(0), right(width), top(height), bottom(0){
	_update = true;

	update();
	matrix[10] = -1.0f;
	matrix[15] = 1.0f;
}

OrthographicCamera::OrthographicCamera(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom){
	_update = true;
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
	update();
	matrix[10] = -1.0f;
	matrix[15] = 1.0f;
}




void OrthographicCamera::init(GLfloat width, GLfloat height){
	_update = true;
	left = 0;
	bottom = 0;

	right = width;
	height = height;
	matrix[10] = -1.0f;
	matrix[15] = 1.0f;
	update();
}

void OrthographicCamera::init(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom){
	_update = true;
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
	matrix[10] = -1.0f;
	matrix[15] = 1.0f;
	update();
}



void OrthographicCamera::update(){
	

	if(_update){
	
		matrix[0] = 2 / (right - left);
		matrix[3] = -(right + left) / (right - left);

		matrix[5] = 2 / (top - bottom);
		matrix[7] = -(top + bottom) / (top - bottom);

		_update = false;
	}

}

void OrthographicCamera::translate(GLfloat x, GLfloat y){
	
	right -= x;
	left -= x;

	top -= y;
	bottom -= y;

	_update = true;

}


void OrthographicCamera::rotateX(GLfloat angle){

	

}

void OrthographicCamera::sendToShader(const GLuint &programID) const{
	
	glUniformMatrix4fv(glGetUniformLocation(programID, "projMatrix"), 1, GL_TRUE, matrix);
}

OrthographicCamera::~OrthographicCamera(){

}
