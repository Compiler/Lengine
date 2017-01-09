#include "ShaderProgram.h"



ShaderProgram::ShaderProgram()
{
}


void ShaderProgram::create(const GLchar *vertexFilePath, const GLchar *fragFilePath) {
	
	GLint shader = glCreateProgram();
	GLuint vert = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);


	std::string vertInfo, fragInfo;


	manager.read(vertexFilePath, vertInfo);
	const GLchar *source = &vertInfo.c_str()[0];
	manager.read(fragFilePath, fragInfo);
	const GLchar *fragSource = &fragInfo.c_str()[0];


	glShaderSource(vert, 1, &source, nullptr);
	glShaderSource(frag, 1, &fragSource, nullptr);

	glCompileShader(vert);
	glCompileShader(frag);

	glAttachShader(shader, vert);
	glAttachShader(shader, frag);

	glLinkProgram(shader);


	glUseProgram(shader);


}

ShaderProgram::~ShaderProgram()
{
}
