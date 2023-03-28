#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "GLAD/glad.h"

class Shader {
public:
	unsigned int id;
	std::string shaderFilePath;
	
	Shader(const std::string& shaderFilePath, GLenum shaderType);

	void setBool(const std::string& name, bool value);
	void setInt(const std::string& name, int value);
	void setFloat(const std::string& name, float value);
	void dealocate();

private:
	std::string getFileContents(const std::string& shaderFilePath);
	bool wasCompilationSucessful(unsigned int shaderId);
};