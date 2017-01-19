#include "OrthographicCamera.h"


#include <iostream>




OrthographicCamera::OrthographicCamera(): left(0), right(640), top(480), bottom(0){

}

OrthographicCamera::OrthographicCamera(GLfloat width, GLfloat height): left(0), right(width), top(height), bottom(0){
	

}

OrthographicCamera::OrthographicCamera(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom){
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}


void OrthographicCamera::init(GLfloat width, GLfloat height){
	left = 0;
	bottom = 0;

	right = width;
	height = height;
}

void OrthographicCamera::init(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom){
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}


OrthographicCamera::~OrthographicCamera(){

}
