#pragma once


#include <GL\glew.h>

class Vector3
{
public:

	GLfloat x, y, z;


	Vector3(GLfloat x, GLfloat y, GLfloat z);
	Vector3(const Vector3 &vec);

	Vector3 &operator =(const Vector3 &vec){ x = vec.x; y = vec.y; z = vec.z; return *this; }
	bool operator ==(const Vector3 &vec){ return vec.x == x && vec.y == y && z == vec.z; }
	bool operator !=(const Vector3 &vec){ return vec.x != x || vec.y != y || z != vec.z; }



	void zero(){ x = y = z = 0.0f; }


	Vector3 operator -(const Vector3 &vec) const;
	Vector3 operator +(const Vector3 &vec) const;
	Vector3 operator *(const Vector3 &vec) const;
	Vector3 operator /(float div) const;

	Vector3 &operator -=(const Vector3 &vec);
	Vector3 &operator +=(const Vector3 &vec);
	Vector3 &operator *=(const Vector3 &vec);
	Vector3 &operator /=(float div);

	~Vector3();
};

