#pragma once

#include <lml\Mat4.h>
#include <lml\Vector2f.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class OrthographicCamera
{
public:
	OrthographicCamera(GLfloat width, GLfloat height);
	OrthographicCamera();


	void init(GLfloat width, GLfloat height);


	void translate(GLfloat xAmount, GLfloat yAmount, GLfloat zAmount);

	void setPosition(const glm::vec2 &newPosition) { position = newPosition; updateCam = true; };

	void scale(GLfloat amount);
	void scale(GLfloat xAmount, GLfloat yAmount);
	void scaleX(GLfloat amount);
	void scaleY(GLfloat amount);

	void update();
	glm::mat4 getMat() { return camMatrix; }
	void setScale(GLfloat newScale) { camScale = newScale; updateCam = true; }
	~OrthographicCamera();


private:


	bool updateCam;
	GLfloat camScale;
	glm::vec2 position;
	glm::vec2 viewport;
	glm::mat4 camMatrix;
	glm::mat4 orthoMatrix;
};

