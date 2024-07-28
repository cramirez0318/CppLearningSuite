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

void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (textSurface == nullptr) {
		std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (textTexture == nullptr) {
		std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << '\n';
		SDL_FreeSurface(textSurface);
		return;
	}

	SDL_Rect renderQuad = { x, y, textSurface->w, textSurface->h };
	SDL_RenderCopy(renderer, textTexture, nullptr, &renderQuad);

	SDL_DestroyTexture(textTexture);
	SDL_FreeSurface(textSurface);
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
		if (!item.second.empty()) {
			renderText(renderer, localMenuNames.at(item.second), 50, y, font, textColor);
			y += 50;
		}
	}

	// Add "Undo" and "Redo" options to the menu
	renderText(renderer, "Undo (U)", 50, y, font, textColor);
	y += 50;
	renderText(renderer, "Redo (R)", 50, y, font, textColor);
	y += 50;

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

// Function to render input fields
void renderInputField(SDL_Renderer* renderer, const std::string& text, int x, int y, int w, int h, TTF_Font* font, SDL_Color color) {
	SDL_Rect inputRect = { x, y, w, h };
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &inputRect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &inputRect);
	renderText(renderer, text, x + 5, y + 5, font, color);
}

// Function to render buttons
void renderButton(SDL_Renderer* renderer, const std::string& text, int x, int y, int w, int h, TTF_Font* font, SDL_Color color) {
	SDL_Rect buttonRect = { x, y, w, h };
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderFillRect(renderer, &buttonRect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &buttonRect);
	renderText(renderer, text, x + 10, y + 10, font, color);
}

// Function to render result displays
void renderResultDisplay(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color) {
	renderText(renderer, text, x, y, font, color);
}

// Function to handle calculator-specific events
void handleCalculatorEvent(SDL_Event& e, std::unordered_map<std::string, std::string>& inputFields, std::string& result) {
	if (e.type == SDL_TEXTINPUT) {
		// Handle text input for input fields
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		// Handle button clicks
	}
}
