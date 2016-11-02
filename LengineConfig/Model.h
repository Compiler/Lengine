#pragma once
#include <GL\glew.h>
#include "ModelVertex.h"
class Model
{
public:
	Model();

	void init(float x, float y, float z, float width, float height);
	void update();
	void render();

	~Model();
private:

	float x, y, z, width, height;
	GLuint vbo;
};

