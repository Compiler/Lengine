#pragma once

#include <iostream>
#include <GL\glew.h>

class Matrix4{
public:
	Matrix4();



	Matrix4 operator*(const GLfloat mine) const;

	Matrix4 operator*(const Matrix4 &other) const;
	Matrix4 operator-(const Matrix4 &other) const;
	Matrix4 operator+(const Matrix4 &other) const;

	~Matrix4();


private:


	GLfloat matrix[16];

};

