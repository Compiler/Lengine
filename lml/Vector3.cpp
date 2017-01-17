#include "Vector3.h"



Vector3::Vector3(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z){

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


Vector3::~Vector3(){


}
