#pragma once

#include "iostream"
#include "math.h"
#include <GL\glew.h>

namespace lml {

	class Vector3f {
	public:
		Vector3f();
		Vector3f(GLfloat xd, GLfloat yd, GLfloat zd);




		GLfloat dot(Vector3f me, Vector3f you) {
			return (me.x * you.x) + (me.y * you.y) + (me.z * you.z);
		}


		GLfloat angleBetween(Vector3f vec);
		GLfloat magnitude();

		Vector3f getProjectionOnto(Vector3f vec);
		Vector3f getNormalized();
		Vector3f getUnitVector();

		void normalize();
		void projectOnto(Vector3f vec);
		void set(GLfloat x, GLfloat y, GLfloat z);
		void set(lml::Vector3f vec);
		//x and y and z components
		GLfloat x, y, z;



		~Vector3f();
	};

}