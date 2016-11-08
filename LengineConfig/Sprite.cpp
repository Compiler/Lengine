#include "Sprite.h"
#include <cstddef>
#include <iostream>


Sprite::Sprite(): vbo(0){
}


void Sprite::init(GLfloat x, GLfloat y, GLfloat width, GLfloat height){

	position.set(x, y);
	this->width = width;
	this->height = height;


	if(vbo == 0)
		glGenBuffers(1, &vbo);

	

	vertex[0].setPosition(x, y);
	vertex[0].setUV(0, 0);

	vertex[1].setPosition(x, y + height);
	vertex[1].setUV(0, 1);

	vertex[2].setPosition(x + width, y + height);
	vertex[2].setUV(1, 1);


	vertex[3].setPosition(x, y);
	vertex[3].setUV(0, 0);

	vertex[4].setPosition(x + width, y);
	vertex[4].setUV(1, 0);

	vertex[5].setPosition(x + width, y + height);
	vertex[5].setUV(1, 1);

	for (int i = 0; i < 3; i++)
		vertex[i].setColor(0.0, 0.0, 255.0, 1.0);
	for (int i = 3; i < 6; i++)
		vertex[i].setColor(255.0, 0.0, 0.0, 1.0);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_DYNAMIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
}



void Sprite::render(){
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

	glDrawArrays(GL_TRIANGLES, 0, 6);
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

}



void Sprite::update(){

}

void Sprite::rotateBy() {
	


}

void Sprite::translate(GLfloat x, GLfloat y) {

	for (int i = 0; i < 6; i++) {
		vertex[i].position.x += x;
		vertex[i].position.y += y;
	
	}

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}



Sprite::~Sprite(){
	if (vbo != 0)
		glDeleteBuffers(1, &vbo);
}
