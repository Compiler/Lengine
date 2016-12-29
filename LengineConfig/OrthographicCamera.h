#pragma once

#include <lml\Mat4.h>

class OrthographicCamera
{
public:
	OrthographicCamera(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat far, GLfloat near);
	OrthographicCamera();


	void init(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat far, GLfloat near);


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


	lml::Mat4 orthographicMatrix, translationMatrix, scaleMatrix, rotationMatrix;



};

