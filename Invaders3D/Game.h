#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <glew.h>
#include "Window.h"
#include "Renderer.h"

class Game
{
public:
	Game() {};
	~Game() {};

	bool initGame();

	void onStart();
	void onStop();
	void startGameLoop();

private:
	bool setupSDL();
	void setAttributes();

	Window window;
	Renderer renderer;
};

