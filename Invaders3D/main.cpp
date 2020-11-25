#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

// Written by Daniel Cumbor in 2020. Thanks Covid-19!

int main(int argc, char** argv)
{
	std::cout << "Hello, World!" << std::endl;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
	}
	SDL_Log("SDL initialised OK!\n");

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		SDL_Log("Mixer could not start: %s\n", SDL_GetError());
	}

	return 1;
}