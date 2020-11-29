#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stb_image.h>

struct Texture
{
	std::string type;
	std::string path;
	unsigned int id;
};

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();

	static unsigned int loadTexture(const char* fileName, const std::string& sourceLocation);

private:


};

