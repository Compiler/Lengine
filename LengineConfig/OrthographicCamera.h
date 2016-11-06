#pragma once
#include <GL/glew.h>
#include "mat4.h"


class OrthographicCamera
{
public:
	OrthographicCamera(int width, int height);

	void translate(float x, float y);
	void flip(bool x, bool y);
	void rotateAbout(float x, float y, float degrees);

	~OrthographicCamera();

private:

	int width, height;

	mat4 matrix;

};

