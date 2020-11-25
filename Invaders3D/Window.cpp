#include "Window.h"

Window::Window()
{
	height = 0;
	width = 0;
	window = nullptr;
}

Window::~Window()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
}

void Window::setViewport(int width, int height)
{
	int finalWidth = width == 0 ? this->width : width;
	int finalHeight = height == 0 ? this->height : height;

	glViewport(0, 0, finalWidth, finalHeight);
}

bool Window::setupWindow(int width, int height, const char* title)
{
	SDL_GetCurrentDisplayMode(0, &dMode);

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	glContext = SDL_GL_CreateContext(window);

	if (window == NULL)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_VIDEO, "SDL failed to create the window! \n");

		return false;
	}
	if (glContext == NULL)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_VIDEO, "SDL failed to create GL Context! \n");

		return false;
	}

	return true;
}
