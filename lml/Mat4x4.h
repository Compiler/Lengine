#pragma once

#include <GL\glew.h>

namespace lml {


	class Mat4x4
	{
	public:
		Mat4x4();
		Mat4x4(GLfloat **matrix);
		void set(GLfloat **newMatrix);

		GLfloat get(int c, int r);

		~Mat4x4();

		Mat4x4 operator* (Mat4x4 other);


	private:
		GLfloat **matrix;

	};

}

