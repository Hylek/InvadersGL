#pragma once
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	unsigned int getShaderProgram();
	void useProgram();

private:
	unsigned int shaderProgram;
	const char* vertexShaderSource;
	const char* fragmentShaderSource;

	unsigned int createShader(GLenum shaderType, const char* shaderSource);
	unsigned int createShaderProgram();
};

