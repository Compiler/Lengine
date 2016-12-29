#include "Mat4x4.h"


namespace lml {

	Mat4x4::Mat4x4(){
	}

	Mat4x4::Mat4x4(GLfloat **matrix){
		this->matrix = matrix;
	}


	Mat4x4::~Mat4x4(){
	}

	GLfloat Mat4x4::get(int c, int r) {
		return matrix[c][r];
	}
	
	void Mat4x4::set(GLfloat **newMatrix) {
		
		matrix = newMatrix;
	}
	Mat4x4 Mat4x4::operator* (Mat4x4 other) {
		GLfloat **newMatrix = {};
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 4; ++k)
				{
					newMatrix[i][j] += matrix[i][k] * other.get(k, j);
				}
		
		return Mat4x4(newMatrix);
	}

}