#include "Vector2f.h"
#include "iostream"


#define TO_DEG 180/3.14159265359
namespace lml {
	/*
		Defaults current Vector2f object to 0 0
	*/
	Vector2f::Vector2f() : x(0), y(0) {
		vals[0] = x;
		vals[1] = y;

	}
	/*
		Gives current Vector2f object GLfloat components 'xd' and 'yd'
	*/
	Vector2f::Vector2f(GLfloat xd, GLfloat yd) {
		x = xd;
		y = yd;
		vals[0] = x;
		vals[1] = y;

	}

	/*
		Sets each component to the given values
	*/
	void Vector2f::set(GLfloat x, GLfloat y) {
		this->x = x;
		this->y = y;
		vals[0] = x;
		vals[1] = y;
	}

	/*
		Sets each component to the given values by passing in another vec3
	*/
	void Vector2f::set(Vector2f vec) {
		set(vec.x, vec.y);
		vals[0] = vec.x;
		vals[1] = vec.y;
	}



	/*
		Returns a vector of the projection but doesn't effect the current
		vector object
	*/
	Vector2f Vector2f::getProjectionOnto(Vector2f vec) {
		/*
			(u * v)
			------- * u
			(u * u)

		*/
		GLfloat projScalar = (dot(*this, vec)) / (dot(*this, *this));
		return Vector2f(projScalar * x, projScalar * y);

	}

	/*
		Modifies the current Vector2f object to be the vector projected onto
		the given Vector2f 'vec'
	*/
	void Vector2f::projectOnto(Vector2f vec) {
		GLfloat projScalar = dot(*this, vec) / dot(*this, *this);
		x = x * projScalar;
		y = y * projScalar;
		vals[0] = x;
		vals[1] = y;
	}


	/*
		Normalizes the current Vector2f object to be
		normalized
	*/
	void Vector2f::normalize() {
		GLfloat tmp = magnitude();
		x = x / tmp;
		y = y / tmp;
		vals[0] = x;
		vals[1] = y;
	}

	/*
		Returns a Vector2f object of the normalized current
		Vector2f object called upon
	*/
	Vector2f Vector2f::getNormalized() {
		GLfloat tmp = magnitude();
		return Vector2f(x / tmp, y / tmp);
	}

	/*
		returns the angle between the invoked Vector2f object
		and the given 'vec' Vector2f object
	*/
	GLfloat Vector2f::angleBetween(Vector2f vec) {
		return acosf(dot(*this, vec) / (magnitude() * vec.magnitude())) * TO_DEG;
	}


	/*
		Returns the magnitude of the currently invoked Vector2f
		object
	*/
	GLfloat Vector2f::magnitude() {

		return sqrtf(powf(x, 2) + powf(y, 2));
	}

	/*
		Returns the unit vector version of this vector
	*/
	Vector2f Vector2f::getUnitVector() {
		return Vector2f(this->x / magnitude(), this->y / magnitude());
	}


	/*
		Destructor
	*/
	Vector2f::~Vector2f() {
	}
}
