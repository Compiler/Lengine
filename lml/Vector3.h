#pragma once


#include <GL\glew.h>
#include <math.h>
namespace lml{

	class Vector3{
	public:

		GLfloat x, y, z;

		Vector3();
		Vector3(const Vector3 &vec);
		Vector3(GLfloat x, GLfloat y, GLfloat z);

		Vector3 &operator =(const Vector3 &vec){ x = vec.x; y = vec.y; z = vec.z; return *this; }
		bool operator ==(const Vector3 &vec){ return vec.x == x && vec.y == y && z == vec.z; }
		bool operator !=(const Vector3 &vec){ return vec.x != x || vec.y != y || z != vec.z; }



		void zero(){ x = y = z = 0.0f; }


		Vector3 operator -(const Vector3 &vec) const;
		Vector3 operator +(const Vector3 &vec) const;
		Vector3 operator *(GLfloat mult) const;
		Vector3 operator /(GLfloat div) const;

		Vector3 &operator -=(const Vector3 &vec);
		Vector3 &operator +=(const Vector3 &vec);
		Vector3 &operator *=(GLfloat mult);
		Vector3 &operator /=(GLfloat div);

		GLfloat operator *(const Vector3 &vec) const;

		void normalize();



		~Vector3();
	};

	// Compute the magnitude of a vector
	inline float vectorMag(const Vector3 &a){
		return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
	}
	// Compute the cross product of two vectors
	static inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b){
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
}