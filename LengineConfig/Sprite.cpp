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
	glGenBuffers(1, &eboID);
	
	glBindBuffer(1, bufferID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STREAM_DRAW);


	glBindBuffer(1, eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexNorm) * 0, reinterpret_cast<GLvoid *>(offsetof(VertexNorm, pos)));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexNorm) * 0, reinterpret_cast<GLvoid *>(offsetof(VertexNorm, normal)));
	glVertexAttribPointer(0, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(VertexNorm) * 0, reinterpret_cast<GLvoid *>(offsetof(VertexNorm, color)));
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(VertexNorm) * 0, reinterpret_cast<GLvoid *>(offsetof(VertexNorm, uv)));



	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 3;


	//LoadBMP(filePath);
}



void Sprite::render(){
	glBindVertexArray(vertexID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);



	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);


	glBindVertexArray(0);
}


Sprite::~Sprite(){
}
