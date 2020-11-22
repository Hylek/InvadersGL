#include "Game.h"

float verticesA[] = {
	// positions          // colors           // texture coords
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};

bool Game::initGame()
{
	if (setupGLFW())
	{
		std::cout << "GLFW initialised OK." << std::endl;
	}
	else
	{
		std::cout << "ERROR: GLFW failed to initialise!" << std::endl;

		return false;
	}

	if (setupGLAD())
	{
		std::cout << "GLAD initialised OK." << std::endl;
	}
	else
	{
		std::cout << "ERROR: GLAD failed to initialise!" << std::endl;

		return false;
	}
	m_Window.setViewport();

	onStart();
	startGameLoop();

	return true;
}

void Game::onStart()
{
	m_Renderer.loadDrawingData(verticesA, sizeof(verticesA));
}

void Game::stop()
{
	glfwTerminate();
}

bool Game::setupGLFW()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (m_Window.setupWindow(800, 600, "Invaders3D"))
	{
		std::cout << "GLFW window created OK." << std::endl;
	}
	else
	{
		return false;
	}

	return true;
}

bool Game::setupGLAD()
{
	return gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void Game::startGameLoop()
{
	while (!glfwWindowShouldClose(m_Window.getWindow()))
	{
		processInput(m_Window.getWindow());

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Renderer.draw();

		glfwSwapBuffers(m_Window.getWindow());
		glfwPollEvents();
	}

	// This method might be redundant if nothing more need be destroyed.
	stop();
}

void Game::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
