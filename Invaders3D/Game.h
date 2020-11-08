#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"

class Game
{
public:
	Game() {};
	~Game() {};

	bool start();
	void stop();

private:
	bool setupGLFW();
	bool setupGLAD();

	void update();

	Window m_Window;
};

