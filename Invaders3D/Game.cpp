#include "Game.h"

float verticesA[] = {
	// positions          // colors
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f  // top left 
};

bool Game::initGame()
{
	if (setupSDL())
	{
		SDL_Log("SDL initialised OK!\n");

		setAttributes();

		if (window.setupWindow(800, 600, "InvadersGL"))
		{
			if (renderer.initOpenGL())
			{
				window.setViewport();

				onStart();
				startGameLoop();
			}
			else
			{
				SDL_Log("ERROR: GLEW did not start!");

				return false;
			}
		}
		else
		{
			SDL_Log("ERROR: Window was not created!");

			return false;
		}
	}
	else
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
	}

	return true;
}

void Game::onStart()
{
}

void Game::onStop()
{
}

void Game::startGameLoop()
{

}

bool Game::setupSDL()
{
	return SDL_Init(SDL_INIT_EVERYTHING) != 0;
}

void Game::setAttributes()
{
	int major = 4;
	int minor = 5;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);

	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &major);
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &minor);
	SDL_Log("Got an OpenGL %d.%d context\n", major, minor);

	SDL_Log("Attributes set OK!\n");
}
