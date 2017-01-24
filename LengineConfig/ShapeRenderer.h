#pragma once
#include <GL\glew.h>
#include "Color.h"
#include "ShaderProgram.h"
#include <vector>

enum ShapeType{
	LINE,
	FILLED
};


struct Vertex{

	//GLfloat position[3];
	//GLubyte color[4];
	GLfloat info[7];
	Vertex(GLfloat xPos, GLfloat yPos, Color col){
		//position[0] = xPos;
		//position[1] = yPos;
		//position[2] = 1.0f;
		//color[0] = col.r;
		//color[1] = col.g;
		//color[2] = col.b;
		//color[3] = col.a;

		info[0] = xPos;
		info[1] = yPos;
		info[2] = 1.0f;

		info[3] = col.r;
		info[4] = col.g;
		info[5] = col.b;
		info[6] = col.a;
	}

//	GLfloat position[2];
	//Color colorC;
};

class ShapeRenderer{
public:
	ShapeRenderer();
	ShapeRenderer(ShapeType type);


	void init();

	void begin();
	void end();
	void drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height);
	void drawTriangle(GLfloat xPos1, GLfloat yPos1, GLfloat xPos2, GLfloat yPos2, GLfloat xPos3, GLfloat yPos3);
	void setColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

	GLuint getShaderID(){ return shader.getProgramID(); }
	~ShapeRenderer();


private:

	ShapeType type;
	Color color;

	GLuint vertexID, bufferID;

	GLuint count;
	std::vector<Vertex> vertices;

	ShaderProgram shader;
};

