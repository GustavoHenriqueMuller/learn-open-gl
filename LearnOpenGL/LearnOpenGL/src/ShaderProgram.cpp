#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const Shader& vertexShader, const Shader& fragmentShader) {
	unsigned int id;
	id = glCreateProgram();

	glAttachShader(id, vertexShader.id);
	glAttachShader(id, fragmentShader.id);

	glLinkProgram(id);

	if (!wasLinkingSuccessful(id)) {
		char infoLog[512];
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;

		exit(-1);
	}

	glUseProgram(id);
	this->id = id;
}

bool ShaderProgram::wasLinkingSuccessful(unsigned int shaderProgramId) {
	int success;
	glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);

	return success;
}