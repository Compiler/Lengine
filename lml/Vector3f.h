#pragma once

#include "iostream"
#include "math.h"
#include <GL\glew.h>

#define TO_DEG 180/3.14159265359

namespace lml {

	class Vector3f {
	public:
		Vector3f();
		explicit Vector3f(GLfloat all);
		Vector3f(GLfloat xd, GLfloat yd, GLfloat zd);




		inline GLfloat dot(Vector3f me, Vector3f you) const { return (me.x * you.x) + (me.y * you.y) + (me.z * you.z); }
		inline GLfloat angleBetween(Vector3f vec) const { return acosf(dot(*this, vec) / (magnitude() * vec.magnitude())) * TO_DEG; }
		inline GLfloat magnitude() const { return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 3)); }
		inline Vector3f getUnitVector() const { return Vector3f(this->x / magnitude(), this->y / magnitude(), this->z / magnitude()); }
		inline Vector3f getUnitVector(Vector3f &vec) const { vec.set(this->x / magnitude(), this->y / magnitude(), this->z / magnitude()); }

		Vector3f getProjectionOnto(Vector3f vec);
		void getProjectionOnto(Vector3f vec, Vector3f &mine);

		inline Vector3f getNormalized() const { return Vector3f(x / magnitude(), y / magnitude(), z / magnitude()); }
		inline void getNormalized(Vector3f &mine) const { mine.set(x / magnitude(), y / magnitude(), z / magnitude()); }
		void normalize();


		void projectOnto(Vector3f vec);
		void set(GLfloat x, GLfloat y, GLfloat z);
		void set(lml::Vector3f vec);
		

		GLfloat x, y, z;



		~Vector3f();
	};

}