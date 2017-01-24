#include "ShapeRenderer.h"



ShapeRenderer::ShapeRenderer():type(ShapeType::LINE){
	
	
}


ShapeRenderer::ShapeRenderer(ShapeType type): type(type){
	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);
	color.red = 255; color.green = 255; color.blue = 255; color.alpha = 255;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

void ShapeRenderer::init(){
	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	color.red = 255; color.green = 255; color.blue = 255; color.alpha = 255;
	shader.create("Shaders/shapes.vert", "Shaders/shapes.frag");

}


void ShapeRenderer::drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height){

	Vertex vertex;
	vertex.setPosition(xPos, yPos);//bottom left
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);
	vertex.setPosition(xPos + width, yPos); // bottom right
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);
	vertex.setPosition(xPos, yPos + height); // top left
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);


	vertex.setPosition(xPos, yPos + height); // top left
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);
	vertex.setPosition(xPos + width, yPos + height); // top right
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);
	vertex.setPosition(xPos + width, yPos); // bottom right
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);

}


void ShapeRenderer::setColor(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha){
	color.red = red; color.green = green; color.blue = blue; color.alpha = alpha;
}

void ShapeRenderer::drawTriangle(GLfloat xPos1, GLfloat yPos1, GLfloat xPos2, GLfloat yPos2, GLfloat xPos3, GLfloat yPos3){
	Vertex vertex;
	vertex.setPosition(xPos1, yPos1);
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);
	vertex.setPosition(xPos2, yPos2);
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);
	vertex.setPosition(xPos3, yPos3);
	vertex.setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex);
	count++;
}


void ShapeRenderer::begin(){
	count = 0;
	vertices.clear();

	shader.useProgram();


}
void ShapeRenderer::end(){
	glBindVertexArray(vertexID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);



	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), (const GLvoid *)&vertices[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, pos)));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, color)));
	

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);




	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);




}

ShapeRenderer::~ShapeRenderer(){
}
