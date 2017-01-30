#pragma once

#include <GL/glew.h>
#include "OrthographicCamera.h"

#include "ShaderProgram.h"
#include "Vertex.h"


class Model{
public:
	Model();



	Model(GLfloat positionX, GLfloat positionY, GLfloat positoinZ, GLfloat width, GLfloat height, GLfloat depth, const char* filePath);

	void init(GLfloat positionX, GLfloat positionY, GLfloat positoinZ, GLfloat width, GLfloat height, GLfloat depth, const char* filePath);

	GLuint getShader(){ return shader.getProgramID(); }

	void render(const OrthographicCamera &camera);


	void translate(GLfloat xAmount, GLfloat yAmount);



	~Model();


private:
	VertexNorm vertex[4];

	GLuint width, height;

	GLuint vertexID;
	GLuint bufferID;
	GLuint eboID;

	GLuint indices[4];

	ShaderProgram shader;

	GLuint textureID;
};

