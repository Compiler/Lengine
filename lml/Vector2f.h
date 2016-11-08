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


		GLfloat angleBetween(Vector2f vec);
		GLfloat magnitude();

		Vector2f getProjectionOnto(Vector2f vec);
		Vector2f getNormalized();


		void normalize();
		void projectOnto(Vector2f vec);

		//x and y components
		GLfloat x, y;


		~Vector2f();



	};

}
