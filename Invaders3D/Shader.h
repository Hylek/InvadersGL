#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader();
	~Shader();

	unsigned int getShaderProgram();
	void setupProgram(const char* vertexPath, const char* fragmentPath);
	void useProgram();

	// Util functions
	void setMat4(const std::string& name, const glm::mat4& mat) const;

private:
	unsigned int shaderProgram;
	const char* vertexShaderSource;
	const char* fragmentShaderSource;

	unsigned int createShader(GLenum shaderType, const char* shaderSource);
	unsigned int createShaderProgram();
};

