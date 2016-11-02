#include "Sprite.h"



Sprite::Sprite(): vbo(0){
}


void Sprite::init(float x, float y, float width, float height){

	if(vbo == 0)
		glGenBuffers(1, &vbo);

	float vertex[12];

	vertex[0] = x;
	vertex[1] = y;

	vertex[2] = x;
	vertex[3] = y + height;

	vertex[4] = x + width;
	vertex[5] = y + height;

	vertex[6] = x;
	vertex[7] = y;

	vertex[8] = x + width;
	vertex[9] = y;

	vertex[10] = x + width;
	vertex[11] = y + height;

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(vbo, sizeof(vertex), vertex, GL_STATIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
}



void Sprite::render(){

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

}



void Sprite::update(){

}


Sprite::~Sprite(){
}
