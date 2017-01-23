#include "ShapeRenderer.h"



ShapeRenderer::ShapeRenderer():type(ShapeType::LINE){
	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);

}


ShapeRenderer::ShapeRenderer(ShapeType type): type(type){
	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}



void ShapeRenderer::drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height){


}


void ShapeRenderer::drawTriangle(GLfloat xPos1, GLfloat yPos1, GLfloat xPos2, GLfloat yPos2, GLfloat xPos3, GLfloat yPos3){
	
}


void ShapeRenderer::begin(){
	count = 0;
	vertices.clear();


}
void ShapeRenderer::end(){



}

ShapeRenderer::~ShapeRenderer(){
}
