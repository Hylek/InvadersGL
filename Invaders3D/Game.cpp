#include "Game.h"

bool Game::start()
{
	if (setupGLFW())
	{
		std::cout << "GLFW initialised OK." << std::endl;
	}
	else
	{
		std::cout << "ERROR: GLFW failed to initialise!" << std::endl;
		glfwTerminate();

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

	update();

	return true;
}

void Game::stop()
{
	glfwTerminate();
}

bool Game::setupGLFW()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
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

void Game::update()
{
	while (!glfwWindowShouldClose(m_Window.getWindow()))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_Window.getWindow());
		glfwPollEvents();
	}

	// This method might be redundant if nothing more need be destroyed.
	stop();
}
