#include "ShaderProgram.h"
#include "IOManager.h"
#include <iostream>
#include <vector>


ShaderProgram::ShaderProgram()
{
}



/*void ShaderProgram::createShaderProgram(const char* vertexShader, const char* fragmentShader) {
	programID = glCreateProgram();
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexID, 1, &vertexShader, nullptr);
	glShaderSource(fragmentID, 1, &fragmentShader, nullptr);

	glCompileShader(vertexID);
	glCompileShader(fragmentID);

	checkCompilationStatus();

	attachShaders();

	linkProgram();

	checkLinkingStatus();

}*/

void ShaderProgram::createShaderProgram(std::string vertexFilePath, std::string fragmentFilePath) {
	programID = glCreateProgram();
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

	compileShader(vertexID, vertexFilePath);
	compileShader(fragmentID, fragmentFilePath);

	checkCompilationStatus();

	attachShaders();

	linkProgram();

	checkLinkingStatus();
}

void ShaderProgram::compileShader(GLint id, std::string filePath) {
	std::string sourceCode;
	IOManager::readToString(filePath, sourceCode);
	const char* temp= sourceCode.c_str();
	glShaderSource(id, 1, &temp, nullptr);
}


void ShaderProgram::checkCompilationStatus() {
	GLint outcome;
	glGetShaderiv(programID, GL_COMPILE_STATUS, &outcome);

	if (outcome == GL_FALSE) {

		GLint maxLength = 0;
		glGetShaderiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

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



	glDetachShader(programID, vertexID);
	glDetachShader(programID, fragmentID);


}

void ShaderProgram::use() {
	glUseProgram(programID);
}
void ShaderProgram::unuse() {
	glUseProgram(0);
}


GLint ShaderProgram::getAttribLocation(std::string name) {
	if (glGetAttribLocation(programID, name.c_str()) == -1)
		std::cout << "Couldn't find '" << name << "' in shader\n";
	else
		std::cout << "Found '" << name << "' in shader\n";
	return glGetAttribLocation(programID, name.c_str());
}

ShaderProgram::~ShaderProgram()
{
}
