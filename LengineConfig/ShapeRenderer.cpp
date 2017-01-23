#include "ShapeRenderer.h"



ShapeRenderer::ShapeRenderer():type(ShapeType::LINE){
	
	
}


ShapeRenderer::ShapeRenderer(ShapeType type): type(type){
	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

void ShapeRenderer::init(){
	type = ShapeType::LINE;

	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);



	shader.create("Shaders/shapes.vert", "Shaders/shapes.frag");

}


void ShapeRenderer::drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height){


}


void ShapeRenderer::drawTriangle(GLfloat xPos1, GLfloat yPos1, GLfloat xPos2, GLfloat yPos2, GLfloat xPos3, GLfloat yPos3){
	vertices.push_back(Vertex(xPos1, yPos1, color));
	vertices.push_back(Vertex(xPos2, yPos2, color));
	vertices.push_back(Vertex(xPos3, yPos3, color));
}


void ShapeRenderer::begin(){
	count = 0;
	vertices.clear();


}
void ShapeRenderer::end(){
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), (GLvoid *)&vertices, GL_DYNAMIC_DRAW);
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (GLvoid *)(sizeof(GLfloat) * 2));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	shader.useProgram();

	glBindVertexArray(vertexID);

	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glBindVertexArray(0);

}

ShapeRenderer::~ShapeRenderer(){
}
