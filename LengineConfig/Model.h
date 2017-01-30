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
	// 3 vertices per triangle
	// 2 triangles per square
	// 6 squares per model/cube
	VertexNorm vertex[3 * 2 * 6];

	GLuint width, height;

	GLuint vertexID;
	GLuint bufferID;
	GLuint eboID;

	GLuint indices[4 * 6];

	ShaderProgram shader;

	GLuint textureID;
};

