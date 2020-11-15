#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include <iostream>


class Renderer
{
public:
	Renderer();
	~Renderer();

	void loadDrawingData(float vertices[], int vertSize, unsigned int indices[] = nullptr, int indSize = -1);
	void draw();

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int shaderProgram;

	unsigned int createShader(GLenum shaderType, const char* shaderSource);
	unsigned int createShaderProgram();
};

