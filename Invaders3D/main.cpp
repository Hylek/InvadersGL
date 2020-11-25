#include <iostream>
#include <SDL.h>

// Written by Daniel Cumbor in 2020. Thanks Covid-19!

int main(int argc, char** argv)
{
	std::cout << "Hello, World!" << std::endl;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
	}
	SDL_Log("SDL initialised OK!\n");

	return 1;
}