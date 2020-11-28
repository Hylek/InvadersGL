#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include <iostream>
#include "Shader.h"
#include "TextureLoader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Renderer
{
public:
	Renderer();
	~Renderer();

	void init(Window* window);
	void loadDrawingData(float vertices[], int vertSize, unsigned int indices[] = nullptr, int indSize = -1);
	void draw();

private:
	Shader shader;
	Window* window;

	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int shaderProgram;
	unsigned int boxTexture;
};

