#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stb_image.h>

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();

	static unsigned int loadTexture(const char* fileName);

private:


};

