#include "Shader.h"

Shader::Shader(const std::string& shaderFilePath, GLenum shaderType) {
	unsigned int id = glCreateShader(shaderType);

	std::string shaderSourceString = getFileContents(shaderFilePath);
	const char* shaderSource = shaderSourceString.c_str();

	glShaderSource(id, 1, &shaderSource, NULL);
	glCompileShader(id);

	if (!wasCompilationSucessful(id)) {
		char infoLog[512];
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;

		exit(-1);
	}

	this->id = id;
	this->shaderFilePath = shaderFilePath;
}

void Shader::dealocate() {
	glDeleteShader(this->id);
}

std::string Shader::getFileContents(const std::string& shaderFileName) {
	std::ifstream ifile(shaderFileName);
	std::string filetext;

	while (ifile.good()) {
		std::string line;
		std::getline(ifile, line);
		filetext.append(line + "\n");
	}

	return filetext;
}

bool Shader::wasCompilationSucessful(unsigned int shaderId) {
	int success;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

	return success;
}