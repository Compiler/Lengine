#pragma once

#include <GL\glew.h>


#include <iostream>

class OrthographicCamera{
public:
	
	OrthographicCamera();
	OrthographicCamera(GLfloat width, GLfloat height);
	OrthographicCamera(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom);

	void init(GLfloat width, GLfloat height);
	void init(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom);

	void sendToShader(const GLuint &programID) const;
	
	void update();
	void translate(GLfloat x, GLfloat y);

	void print(){
		
		for(int i = 0; i < 16; i++)
			if(i % 4 != 0) std::cout << matrix[i] << ", ";
			else std::cout << "\n" << matrix[i] << ", ";
	}

	~OrthographicCamera();

private:

	GLfloat left, right, top, bottom;
	GLfloat matrix[16] = {0.0f};

	GLboolean _update;
};

