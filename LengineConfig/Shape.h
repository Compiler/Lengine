#pragma once
#include <GL\glew.h>
#include "ShaderProgram.h"
#include "Vertex.h"
class Shape {

public:
	virtual void create(GLfloat x, GLfloat y, GLfloat width, GLfloat height, color color) = 0;
	virtual void draw() = 0;
protected:
	ShaderProgram program;
	GLuint arrayID, bufferID;
};

class Triangle : Shape {

public:
	void create(GLfloat x, GLfloat y, GLfloat width, GLfloat height, color color) {
		program.createShaderProgram("Shaders/passthrough.vert", "Shaders/passthrough.frag");
		
		GLint positionAttribute = program.getAttribLocation("position");
		GLint colorAttribute = program.getAttribLocation("color");

		glGenVertexArrays(1, &arrayID);
		glBindVertexArray(arrayID);

		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);


		Vertex vertices[3];
		vertices[0].setPosition(x, y);
		vertices[0].color.set(color);

		vertices[1].setPosition(x + width, y);
		vertices[1].color.set(color);

		vertices[2].setPosition(x + (width / 2.0f), y + height);
		vertices[2].color.set(color);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(positionAttribute);
		glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, position));

		glEnableVertexAttribArray(colorAttribute);
		glVertexAttribPointer(colorAttribute, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, color));

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}


	void draw() {
		program.use();

		glBindVertexArray(arrayID);
		
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);

		glBindVertexArray(0);

		program.unuse();
	}

};