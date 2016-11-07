#include "Vector2f.h"
#include "iostream"


#define TO_DEG 180/3.14159265359

/*
	Defaults current Vector2f object to 0 0
*/
Vector2f::Vector2f(): x(0), y(0){
	

}
/*
	Gives current Vector2f object float components 'xd' and 'yd'
*/
Vector2f::Vector2f(float xd, float yd){
	x = xd;
	y = yd;
	
}



/*
	Returns a vector of the projection but doesn't effect the current
	vector object
*/
Vector2f Vector2f::getProjectionOnto(Vector2f vec){
	/*
		(u * v)
		------- * u
		(u * u)
		
	*/
	float projScalar = (dot(*this, vec)) / (dot(*this, *this));
	return Vector2f(projScalar * x, projScalar * y);

}

/*
	Modifies the current Vector2f object to be the vector projected onto
	the given Vector2f 'vec'
*/
void Vector2f::projectOnto(Vector2f vec){
	float projScalar = dot(*this, vec) / dot(*this, *this);
	x = x * projScalar;
	y = y * projScalar;
}


/*
	Normalizes the current Vector2f object to be
	normalized
*/
void Vector2f::normalize(){
	float tmp = magnitude();
	x = x / tmp;
	y = y / tmp;
}

/*
	Returns a Vector2f object of the normalized current
	Vector2f object called upon
*/
Vector2f Vector2f::getNormalized(){
	float tmp = magnitude();
	return Vector2f(x / tmp, y / tmp);
}

/*
	returns the angle between the invoked Vector2f object
	and the given 'vec' Vector2f object
*/
float Vector2f::angleBetween(Vector2f vec){
	return acosf(dot(*this, vec) / (magnitude() * vec.magnitude())) * TO_DEG;
}


/*
	Returns the magnitude of the currently invoked Vector2f
	object
*/
float Vector2f::magnitude(){
	
	return sqrtf(powf(x, 2) + powf(y, 2));
}


/*
	Destructor
*/
Vector2f::~Vector2f(){
}
