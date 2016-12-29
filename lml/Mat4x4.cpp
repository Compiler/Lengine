#include "Mat4x4.h"

#include <iostream>

namespace lml {

	Mat4x4::Mat4x4() {
	}

	Mat4x4::Mat4x4(GLfloat matrix[4][4]) {
		memcpy(this->matrix, matrix, sizeof(this->matrix));
	}


	Mat4x4::~Mat4x4() {
	}

	GLfloat Mat4x4::get(int c, int r) {
		return matrix[c][r];
	}

	void Mat4x4::set(GLfloat newMatrix[4][4]) {
		memcpy(this->matrix, newMatrix, sizeof(this->matrix));
	}

	void Mat4x4::setElement(int row, int column, GLfloat value) {
		matrix[row][column] = value;
	}


	//O(n^3)  :(
	Mat4x4 Mat4x4::operator* (Mat4x4 other) {
		GLfloat newMatrix[4][4] = {};
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 4; ++k)
				{
					newMatrix[i][j] += matrix[i][k] * other.get(k, j);
				}
		Mat4x4 next(newMatrix);
		return next;
	}

	Mat4x4 Mat4x4::operator+ (Mat4x4 other) {
		GLfloat newMatrix[4][4] = {};
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				newMatrix[row][column] = matrix[row][column] + other[row][column];
			}
		}

		return Mat4x4(newMatrix);
	
	}











	void Mat4x4::print() {
		for (int i = 0; i < 4; i++) {
			std::cout << "[ ";
			for (int k = 0; k < 4; k++) {
				std::cout << matrix[i][k] << ", ";
			}
			std::cout << "]\n";
		}
		std::cout << "\n";
	}

}