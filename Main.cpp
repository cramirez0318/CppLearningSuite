#include <SDL.h>
#include <SDL_main.h>
#include "Menu.h"
#include "graphics/MenuGraphics.h"
#include <iostream>
#include <cstdlib>

int main(int /*argc*/, char* /*argv*/[]) {
	if (!initSDL()) {
		std::cerr << "Failed to initialize SDL and SDL_ttf.\n";
		return EXIT_FAILURE;
	}

	SDL_Window* window = SDL_CreateWindow("C++ Learning Suite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
		closeSDL();
		return EXIT_FAILURE;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << '\n';
		SDL_DestroyWindow(window);
		closeSDL();
		return EXIT_FAILURE;
	}

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else {
				handleMainMenuChoice(e);
			}
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		displayMainMenu(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	closeSDL();

	return EXIT_SUCCESS;
}
