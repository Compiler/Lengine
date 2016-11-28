#pragma once
#include "iostream"
#include "math.h"
#include <GL\glew.h>
namespace lml {
	class Vector2f {
	public:
		Vector2f();
		Vector2f(GLfloat xd, GLfloat yd);




		static GLfloat dot(Vector2f me, Vector2f you) {
			return (me.x * you.x) + (me.y * you.y);
		}

		static Vector2f ZERO() {
			return Vector2f(0.0f, 0.0f);
		}


		GLfloat angleBetween(Vector2f vec);
		GLfloat magnitude();

		Vector2f getProjectionOnto(Vector2f vec);
		Vector2f getNormalized();
		Vector2f getUnitVector();

		void normalize();
		void projectOnto(Vector2f vec);
		void set(GLfloat x, GLfloat y);
		void set(Vector2f vec);
		//x and y components
		GLfloat x, y;
		GLfloat vals[2];

		~Vector2f();



	};

}
