#pragma once

#include <lml\Mat4.h>
#include <lml\Vector2f.h>

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

	GLfloat* getValuePointer() {
		return orthographicMatrix.valuePointer();
	}
	~OrthographicCamera();


private:


	lml::Mat4 orthographicMatrix, cameraMatrix;
	lml::Vector2f position, viewport;

};

