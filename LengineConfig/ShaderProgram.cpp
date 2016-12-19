#include "ShaderProgram.h"
#include "IOManager.h"
#include <iostream>



ShaderProgram::ShaderProgram()
{
}



void ShaderProgram::createShaderProgram(const char* vertexShader, const char* fragmentShader) {
	programID = glCreateProgram();
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexID, 1, &vertexShader, nullptr);
	glShaderSource(fragmentID, 1, &fragmentShader, nullptr);

	glCompileShader(vertexID);
	glCompileShader(fragmentID);


	attachShaders();

	linkProgram();

}

void ShaderProgram::createShaderProgram(std::string vertexFilePath, std::string fragmentFilePath) {
	programID = glCreateProgram();
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

	compileShader(vertexID, vertexFilePath);
	compileShader(fragmentID, fragmentFilePath);

	checkCompilationStatus();

	attachShaders();

	linkProgram();
}

void ShaderProgram::compileShader(GLint id, std::string filePath) {
	std::string sourceCode;
	IOManager::readToString(filePath, sourceCode);
	const char* temp= sourceCode.c_str();
	glShaderSource(id, 1, &temp, nullptr);
}


void ShaderProgram::checkCompilationStatus() {
	GLint outcome = 0;
	glGetShaderiv(programID, GL_COMPILE_STATUS, &outcome);

	if (outcome == GL_FALSE) {
		GLchar message[256];
		glGetShaderInfoLog(programID, sizeof(message), 0, &message[0]);
		std::cout << "Shader Compilation FAILED\n" << message;
	}

}

void ShaderProgram::attachShaders() {

	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);

}

void ShaderProgram::linkProgram() {

	glLinkProgram(programID);

}

void ShaderProgram::checkLinkingStatus() {
	GLint linkStatus, validateStatus;

	//Check Linking Status
	glGetProgramiv(programID, GL_LINK_STATUS, &linkStatus);

	if (linkStatus == GL_FALSE) {
		GLchar message[256];
		glGetProgramInfoLog(programID, sizeof(message), 0, &message[0]);
		std::cout << "Linking of program FAILED\n" << message;
	}//End of Checking Linking Status

	//Check Validation Status

	glValidateProgram(programID);
	glGetProgramiv(programID, GL_VALIDATE_STATUS, &validateStatus);

	if (validateStatus == GL_FALSE) {
		GLchar message[256];
		glGetProgramInfoLog(programID, sizeof(message), 0, &message[0]);
		std::cout << "Validation of program FAILED\n" << message;
	}//End of Checking Validation Status



}

void ShaderProgram::use() {
	glUseProgram(programID);
}
void ShaderProgram::unuse() {
	glUseProgram(0);
}

ShaderProgram::~ShaderProgram()
{
}
