#include "Model.h"
#include "ModelVertex.h"
#include <cstddef>

Model::Model()
{
}


void Model::init(float x, float y, float z, float width, float height) {

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;


	if (vbo == 0)
		glGenBuffers(1, &vbo);
	
	ModelVertex vertex[6];

	vertex[0].setPosition(-0.5f, -0.5f, -0.5f);
	vertex[0].setUV(0, 0);

	vertex[1].setPosition(-0.5f, -0.5f, 0.5f);
	vertex[1].setUV(0, 1);

	vertex[2].setPosition(-0.5f, 0.5f, 0.5f);
	vertex[2].setUV(1, 1);


	vertex[3].setPosition(0.5f, 0.5f, -0.5f);
	vertex[3].setUV(0, 0);

	vertex[4].setPosition(-0.5f, -0.5f, -0.5f);
	vertex[4].setUV(1, 0);
	
	vertex[5].setPosition(-0.5f, 0.5f, -0.5f);
	vertex[5].setUV(1, 1);


	vertex[0].setColor(255, 255, 255, 255);
	vertex[1].setColor(0, 255, 255, 255);
	vertex[2].setColor(255, 0, 255, 255);
	vertex[3].setColor(255, 255, 0, 255);
	vertex[4].setColor(255, 0, 0, 255);
	vertex[5].setColor(00, 0, 255, 255);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_DYNAMIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, 0);

}



void Model::render() {

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ModelVertex), (void*)offsetof(ModelVertex, position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(ModelVertex), (void*)offsetof(ModelVertex, color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ModelVertex), (void*)offsetof(ModelVertex, uv));

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

}



void Model::update() {

}


Model::~Model()
{
}
