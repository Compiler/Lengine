#include "Vector3f.h"
#define TO_DEG 180/3.14159265359

/*
Defaults current Vector3f object to 0 0
*/
Vector3f::Vector3f(): x(0), y(0){


}
/*
Gives current Vector3f object float components 'xd' and 'yd' and 'zd'
*/
Vector3f::Vector3f(float xd, float yd, float zd){
	x = xd;
	y = yd;
	z = zd;

}



/*
Returns a vector of the projection but doesn't effect the current
vector object
*/
Vector3f Vector3f::getProjectionOnto(Vector3f vec){

	float projScalar = (dot(*this, vec)) / (dot(*this, *this));
	return Vector3f(projScalar * x, projScalar * y, projScalar * z);

}

/*
Modifies the current Vector3f object to be the vector projected onto
the given Vector3f 'vec'
*/
void Vector3f::projectOnto(Vector3f vec){
	float projScalar = dot(*this, vec) / dot(*this, *this);
	x = x * projScalar;
	y = y * projScalar;
	z = z * projScalar;
}


/*
Normalizes the current Vector3f object to be
normalized
*/
void Vector3f::normalize(){
	float tmp = magnitude();
	x = x / tmp;
	y = y / tmp;
	z = z / tmp;
}

/*
Returns a Vector3f object of the normalized current
Vector3f object called upon
*/
Vector3f Vector3f::getNormalized(){
	float tmp = magnitude();
	return Vector3f(x / tmp, y / tmp, z / tmp);
}

/*
returns the angle between the invoked Vector3f object
and the given 'vec' Vector3f object
*/
float Vector3f::angleBetween(Vector3f vec){
	return acosf(dot(*this, vec) / (magnitude() * vec.magnitude())) * TO_DEG;
}


/*
Returns the magnitude of the currently invoked Vector3f
object
*/
float Vector3f::magnitude(){

	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 3));
}


/*
Destructor
*/
Vector3f::~Vector3f(){
}