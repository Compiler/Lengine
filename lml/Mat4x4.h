#pragma once

#include <GL\glew.h>

namespace lml {


	class Mat4x4
	{
	public:
		Mat4x4();
		Mat4x4(GLfloat matrix[4][4]);
		void set(GLfloat matrix[4][4]);

		GLfloat get(int c, int r);

		~Mat4x4();

		Mat4x4 operator* (Mat4x4 other);


		//for testing
		void print();
	private:
		GLfloat matrix[4][4];

	};

}

