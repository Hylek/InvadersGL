#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct DrawingData
{
	bool hasTexture;
	unsigned int texture;
	float vertices[];
};

// Base class from which all game entities derive from.
// Contains essential drawing data and base functions.
class Entity
{
public:
	Entity();
	~Entity();

private:
	DrawingData data;

};

