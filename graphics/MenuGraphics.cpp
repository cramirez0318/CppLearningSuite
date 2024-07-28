#include "MenuGraphics.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <unordered_map>
#include <vector>

bool initSDL() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}

	if (TTF_Init() == -1) {
		std::cerr << "SDL_ttf could not initialize! TTF_Error: " << TTF_GetError() << '\n';
		SDL_Quit();
		return false;
	}

	return true;
}

void closeSDL() {
	TTF_Quit();
	SDL_Quit();
}

void renderMainMenu(SDL_Renderer* renderer, const std::vector<std::pair<int, std::string>>& localMenuOrder, const std::unordered_map<std::string, std::string>& localMenuNames) {
	TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}

	SDL_Color textColor = { 0, 0, 0, 255 };
	int y = 50;

	for (const auto& item : localMenuOrder) {
		renderText(renderer, localMenuNames.at(item.second), 50, y, font, textColor);
		y += 50;
	}

	renderText(renderer, "Undo (U)", 50, y, font, textColor);
	y += 50;
	renderText(renderer, "Redo (R)", 50, y, font, textColor);

	TTF_CloseFont(font);
}

void handleMenuEvent(SDL_Event& e, std::unordered_map<std::string, MenuFunction>& localMenuOptions) {
	if (e.type == SDL_KEYDOWN) {
		std::string choice(1, static_cast<char>(e.key.keysym.sym));
		auto it = localMenuOptions.find(choice);
		if (it != localMenuOptions.end()) {
			it->second();
		}
	}
}

