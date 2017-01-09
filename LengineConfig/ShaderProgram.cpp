#include "ShaderProgram.h"

#include <iostream>

ShaderProgram::ShaderProgram()
{
}


void ShaderProgram::create(const GLchar *vertexFilePath, const GLchar *fragFilePath) {
	
	_shaderProgramID = glCreateProgram();
	_vertexID = glCreateShader(GL_VERTEX_SHADER);
	_fragmentID = glCreateShader(GL_FRAGMENT_SHADER);


	std::string vertInfo, fragInfo;


	_manager.read(vertexFilePath, vertInfo);
	const GLchar *source = &vertInfo.c_str()[0];
	_manager.read(fragFilePath, fragInfo);
	const GLchar *fragSource = &fragInfo.c_str()[0];


	glShaderSource(_vertexID, 1, &source, nullptr);
	glShaderSource(_fragmentID, 1, &fragSource, nullptr);

	glCompileShader(_vertexID);
	glCompileShader(_fragmentID);

	GLint compileStatus;
	glGetShaderiv(_shaderProgramID, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus == GL_FALSE) {
		GLchar message[256];
		glGetShaderInfoLog(_shaderProgramID, sizeof(message), 0, &message[0]);
		std::cout << "Couldn't compile shader:\n" << message;
	}


	glAttachShader(_shaderProgramID, _vertexID);
	glAttachShader(_shaderProgramID, _fragmentID);

	glLinkProgram(_shaderProgramID);


	glUseProgram(_shaderProgramID);


}


void ShaderProgram::useProgram() {
	glUseProgram(_shaderProgramID);
}

void ShaderProgram::unuseProgram() {
	glUseProgram(0);
}

ShaderProgram::~ShaderProgram()
{
}
