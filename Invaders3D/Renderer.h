#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <glew.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool initOpenGL();

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int shaderProgram;
};

