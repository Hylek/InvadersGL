#pragma once
#include <SDL.h>
#include <glew.h>

class Window
{
public:
	Window();
	~Window();

	void setViewport(int width = 0, int height = 0);
	bool setupWindow(int width, int height, const char* title);

private:
	SDL_Window* window;
	SDL_DisplayMode dMode;
	SDL_Event e;
	SDL_GLContext glContext;

	bool closed;
	int width;
	int height;
};

