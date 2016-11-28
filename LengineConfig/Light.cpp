#include "Light.h"



Light::Light()
{
}

void Light::init(GLfloat positionX, GLfloat positionY, GLfloat radius) {
	
	information.x = positionX;
	information.y = positionY;
	information.z = radius;


}


void Light::init(lml::Vector2f position, GLfloat radius) {

	information.x = position.x;
	information.y = position.y;

	information.z = radius;

	

}

void Light::set(GLint programID) {

	GLfloat a[3] = { information.x, information.y, information.z };
	glUniform3fv(programID, 1, a);
}


Light::~Light()
{
}
