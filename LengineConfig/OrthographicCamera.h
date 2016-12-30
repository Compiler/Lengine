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

	void scale(GLfloat amount);
	void scale(GLfloat xAmount, GLfloat yAmount);
	void scaleX(GLfloat amount);
	void scaleY(GLfloat amount);

	void update();
	//GLfloat* getValuePointer() {
	//	return orthographicMatrix.valuePointer();
	//}
	

	glm::mat4 getMat() { return camMatrix; }
	void setPosition(const glm::vec2& newPosition) { position = newPosition; updateCam = true; }
	void setScale(GLfloat newScale) { camScale = newScale; updateCam = true; }
	~OrthographicCamera();


private:


	//lml::Mat4 orthographicMatrix, cameraMatrix;
	//lml::Vector2f position, viewport;


	bool updateCam;
	GLfloat camScale;
	glm::vec2 position;
	glm::vec2 viewport;
	glm::mat4 camMatrix;
	glm::mat4 orthoMatrix;
};

