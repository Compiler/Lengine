#include "Sprite.h"



Sprite::Sprite(){
}


Sprite::Sprite(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height, const char* filePath){
	
	vertex[PositionTuples::BOTTOM_LEFT].setPosition(positionX, positionY);
	vertex[PositionTuples::BOTTOM_LEFT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::TOP_LEFT].setPosition(positionX, positionY + height);
	vertex[PositionTuples::TOP_LEFT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::TOP_RIGHT].setPosition(positionX + width, positionY + height);
	vertex[PositionTuples::TOP_RIGHT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::BOTTOM_RIGHT].setPosition(positionX + width, positionY);
	vertex[PositionTuples::BOTTOM_RIGHT].setNormal(1.0f, 1.0f);

	shader.create("Shaders/passthrough.vert", "Shaders/passthrough.frag");

	//LoadBMP(filePath);

}

void Sprite::init(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height, const char* filePath) {

	vertex[PositionTuples::BOTTOM_LEFT].setPosition(positionX, positionY);
	vertex[PositionTuples::BOTTOM_LEFT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::TOP_LEFT].setPosition(positionX, positionY + height);
	vertex[PositionTuples::TOP_LEFT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::TOP_RIGHT].setPosition(positionX + width, positionY + height);
	vertex[PositionTuples::TOP_RIGHT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::BOTTOM_RIGHT].setPosition(positionX + width, positionY);
	vertex[PositionTuples::BOTTOM_RIGHT].setNormal(1.0f, 1.0f);

	shader.create("Shaders/passthrough.vert", "Shaders/passthrough.frag");



	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(1, bufferID);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STREAM_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexNorm) * 0, reinterpret_cast<GLvoid *>(offsetof(VertexNorm, pos)));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexNorm) * 0, reinterpret_cast<GLvoid *>(offsetof(VertexNorm, pos)));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexNorm) * 0, reinterpret_cast<GLvoid *>(offsetof(VertexNorm, pos)));




	//LoadBMP(filePath);
}



void Sprite::render(){
	glEnableVertexAttribArray(vertexID);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

}


Sprite::~Sprite(){
}
