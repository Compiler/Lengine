#pragma once

#include "iostream"
#include "math.h"


class Vector3f{
public:
	Vector3f();
	Vector3f(float xd, float yd, float zd);




	float dot(Vector3f me, Vector3f you){
		return (me.x * you.x) + (me.y * you.y) + (me.z * you.z);
	}


	float angleBetween(Vector3f vec);
	float magnitude();

	Vector3f getProjectionOnto(Vector3f vec);
	Vector3f getNormalized();

	void normalize();
	void projectOnto(Vector3f vec);


	//x and y components
	float x, y, z;



	~Vector3f();
};

