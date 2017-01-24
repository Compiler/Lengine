#include "Vector3.h"
#include <math.h>


Vector3::Vector3(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z){

}


Vector3::Vector3(): x(0.0f), y(0.0f), z(0.0f){

}
Vector3::Vector3(const Vector3 &vec){
	x = vec.x;
	y = vec.y;
	z = vec.z;
}


Vector3 Vector3::operator -(const Vector3 &vec) const{
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3 Vector3::operator +(const Vector3 &vec) const{
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

Vector3 Vector3::operator *(GLfloat mult) const{
	return Vector3(x * mult, y * mult, z * mult);
}

Vector3 Vector3::operator /(GLfloat div) const{
	return Vector3(x / div, y / div, z / div);
}


Vector3 &Vector3::operator -=(const Vector3 &vec){
	x -= vec.x; y -= vec.y; z -= vec.z;
	return *this;
}

Vector3 &Vector3::operator +=(const Vector3 &vec){
	x += vec.x; y += vec.y; z += vec.z;
	return *this;
}

Vector3 &Vector3::operator *=(GLfloat mult){
	x *= mult; y *= mult; z *= mult;
	return *this;
}

Vector3 &Vector3::operator /=(GLfloat div){
	float mult = 1.0f / div;
	x *= mult; y *= mult; z *= mult;
	return *this;
}


GLfloat Vector3::operator *(const Vector3 &vec) const{
	return (x * vec.x) + (y * vec.y) + (z * vec.z);
}


void Vector3::normalize(){
	GLfloat magSq = x*x + y*y + z*z;
	if(magSq > 0.0f){ // check for divide-by-zero
		GLfloat oneOverMag = 1.0f / sqrt(magSq);
		x *= oneOverMag;
		y *= oneOverMag;
		z *= oneOverMag;
	}
}

Vector3::~Vector3(){


}



// Compute the magnitude of a vector
inline float vectorMag(const Vector3 &a){
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}
// Compute the cross product of two vectors
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b){
	return Vector3(
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x
	);
}
// Scalar on the left multiplication, for symmetry
inline Vector3 operator *(float k, const Vector3 &v){
	return Vector3(k*v.x, k*v.y, k*v.z);
}
// Compute the distance between two points
inline float distance(const Vector3 &a, const Vector3 &b){
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

extern const Vector3 kZeroVector;
