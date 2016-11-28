#pragma once

#include <GL/glew.h>
#include <lml\Vector3f.h>
#include <lml\Vector2f.h>

class Light
{
public:
	Light();

	void init(GLfloat positionX, GLfloat positionY, GLfloat radius);
	void init(lml::Vector2f position, GLfloat radius);
	void set(GLint programID);
	~Light();

private:
	lml::Vector3f information;
	static int count;
};

