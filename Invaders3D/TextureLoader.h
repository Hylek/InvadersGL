#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <iostream>

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();

	unsigned int loadTexture(const char* fileName);

private:


};

