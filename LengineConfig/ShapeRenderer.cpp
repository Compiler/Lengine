#include "ShapeRenderer.h"



ShapeRenderer::ShapeRenderer():type(ShapeType::LINE){
	
	
}


ShapeRenderer::ShapeRenderer(ShapeType type): type(type){
	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);
	color.red = 1.0f; color.green = 1.0f; color.blue = 1.0f; color.alpha = 1.0f;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

void ShapeRenderer::init(){
	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	color.red = 1.0f; color.green = 1.0f; color.blue = 1.0f; color.alpha = 1.0f;
	shader.create("Shaders/shapes.vert", "Shaders/shapes.frag");

}


void ShapeRenderer::drawRectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height){


}


void ShapeRenderer::setColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){
	//color.set(red, green,blue, alpha);
}

void ShapeRenderer::drawTriangle(GLfloat xPos1, GLfloat yPos1, GLfloat xPos2, GLfloat yPos2, GLfloat xPos3, GLfloat yPos3){
	Vertex vertex[3];
	vertex[0].setPosition(xPos1, yPos1);
	vertex[0].setColor(color.red, color.green, color.blue, color.alpha);
	vertex[1].setPosition(xPos2, yPos2);
	vertex[1].setColor(color.red, color.green, color.blue, color.alpha);
	vertex[2].setPosition(xPos3, yPos3);
	vertex[2].setColor(color.red, color.green, color.blue, color.alpha);
	vertices.push_back(vertex[0]);
	vertices.push_back(vertex[1]);
	vertices.push_back(vertex[2]);
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

	GLfloat stuff[2*3 + 4*4] = {100, 100, 200, 100, 50, 200,  1, 1, 1, 1,  1, 1, 1, 1,  1,1,1,1,  1,1,1,1};
	//glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), (const GLvoid *)&vertices, GL_DYNAMIC_DRAW);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, position)));
	//glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, color)));
	
	
	//GLfloat *data = new GLfloat[vertices.size() * 7];
	//int mine = 0;
	//for(int i = 0; i < vertices.size(); i++){
	//	for(int k = 0; k < 7; k++){
	//		data[mine++] = vertices[i].info[k];
	//	}
	//}
	//glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), (const GLvoid *)data, GL_DYNAMIC_DRAW);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	//glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(sizeof(GLfloat) * 3));

	//glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 22, (const GLvoid *)&stuff, GL_DYNAMIC_DRAW);
	//glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex) * 0, 0);
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex) * 0, (GLvoid *)(sizeof(GLfloat) * 6));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);




	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);




}

ShapeRenderer::~ShapeRenderer(){
}
