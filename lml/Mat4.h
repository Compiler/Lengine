#pragma once

#include <GL\glew.h>
#include "Vector3f.h"

namespace lml {


	class Mat4
	{
	public:
		Mat4();
		Mat4(GLfloat matrix[4][4]);
		void set(GLfloat matrix[4][4]);
		void setElement(int row, int column, GLfloat value);
		void addElement(int row, int column, GLfloat value);
		GLfloat get(int row, int column);

		~Mat4();

		Mat4 operator* (Mat4 other);
		Mat4 operator* (Mat4 other);
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

