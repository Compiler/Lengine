#pragma once
#include <GL\glew.h>
class mat4
{
public:
	mat4();
	mat4(GLfloat row1[4], GLfloat row2[4], GLfloat row3[4], GLfloat row4[4]);
	mat4(GLfloat mat[4][4]);
	mat4(GLfloat linear[16]);

	void initByRow(GLfloat row1[4], GLfloat row2[4], GLfloat row3[4], GLfloat row4[4]);
	void initByMat(GLfloat mat[4][4]);
	void initByArray(GLfloat linear[16]);

	GLfloat* getLinear();

	GLfloat getElement(GLint x, GLint y);
	~mat4();

private:
	GLfloat matrix[4][4];
	GLfloat linMat[16];
};

