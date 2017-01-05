#pragma once

#include <GL\glew.h>
#include "Vector3f.h"

namespace lml {


	class Mat4
	{
	public:
		Mat4();
		Mat4(GLfloat matrix[4][4]);
		inline void set(GLfloat newMatrix[4][4]) { memcpy(this->matrix, newMatrix, sizeof(this->matrix)); }
		inline void setElement(int row, int column, GLfloat value){matrix[row][column] = value;}
		void addElement(int row, int column, GLfloat value);
		inline GLfloat get(int row, int column)const { return matrix[row][column]; }

		~Mat4();

		Mat4 operator* (Mat4 other);
//		Mat4 operator* (Mat4 other);
		Mat4 operator+ (Mat4 other);


		GLfloat* valuePointer() {
			return matrix[0];
		}

		//for testing
		void print();
	private:
		GLfloat matrix[4][4];

	};

}

