#pragma once

#include <string>

#include "Shader.h"

class ShaderProgram {
public:
	unsigned int id;

	ShaderProgram(const Shader& vertexShader, const Shader& fragmentShader);

private:
	bool wasLinkingSuccessful(unsigned int shaderProgramId);
};

