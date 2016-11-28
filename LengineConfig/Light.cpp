#include "Light.h"



Light::Light()
{
}

void Light::init(GLfloat positionX, GLfloat positionY, GLfloat radius) {
	


}


void Light::init(lml::Vector2f position, GLfloat radius) {

	information.x = position.x;
	information.y = position.y;

	information.z = radius;

	

}

void Light::set(GLint programID) {

	
	glUniform3fv(glGetUniformLocation(programID, "light0"), 1, information);
}


Light::~Light()
{
}
