#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Renderer.h"

class Game
{
public:
	Game() {};
	~Game() {};

	bool initGame();

	void onStart();
	void stop();

private:
	bool setupGLFW();
	bool setupGLAD();

	void startGameLoop();
	void processInput(GLFWwindow* window);

	Window m_Window;
	Renderer m_Renderer;
};

