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

	void loadDrawingData(Window* window, float vertices[], int size);
	void draw();

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int shaderProgram;

	unsigned int createShader(GLenum shaderType, const char* shaderSource);
	unsigned int createShaderProgram();
};

