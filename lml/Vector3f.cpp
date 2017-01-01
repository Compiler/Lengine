#include "Vector3f.h"

namespace lml {
	/*
	Defaults current Vector3f object to 0 0
	*/
	Vector3f::Vector3f() : x(0), y(0), z(0) {}
	/*
	Gives current Vector3f object GLfloat components 'xd' and 'yd' and 'zd'
	*/
	Vector3f::Vector3f(GLfloat xd, GLfloat yd, GLfloat zd): x(xd), y(yd), z(zd) {}

	Vector3f::Vector3f(GLfloat all): x(all), y(all), z(all) {}

	/*
		Easier way to set
	*/
	void Vector3f::set(GLfloat x, GLfloat y, GLfloat z) {
		this->x = x;
		this->y = y;
		this->z = z;

	}
	/*
		Sets, calls inner method to do so
	*/
	void Vector3f::set(lml::Vector3f vec) {
		set(vec.x, vec.y, vec.z);
	}



	/*
	Returns a vector of the projection but doesn't effect the current
	vector object
	*/
	Vector3f Vector3f::getProjectionOnto(Vector3f vec) {

		GLfloat projScalar = (dot(*this, vec)) / (dot(*this, *this));
		return Vector3f(projScalar * x, projScalar * y, projScalar * z);

	}

	/*
	Modifies the current Vector3f object to be the vector projected onto
	the given Vector3f 'vec'
	*/
	void Vector3f::projectOnto(Vector3f vec) {
		GLfloat projScalar = dot(*this, vec) / dot(*this, *this);
		x = x * projScalar;
		y = y * projScalar;
		z = z * projScalar;
	}


	/*
	Normalizes the current Vector3f object to be
	normalized
	*/
	void Vector3f::normalize() {
		GLfloat tmp = magnitude();
		x = x / tmp;
		y = y / tmp;
		z = z / tmp;
	}

	/*
	Returns a Vector3f object of the normalized current
	Vector3f object called upon
	*/
	Vector3f Vector3f::getNormalized() {
		GLfloat tmp = magnitude();
		return Vector3f(x / tmp, y / tmp, z / tmp);
	}




	/*
	Destructor
	*/
	Vector3f::~Vector3f() {
	}
}
