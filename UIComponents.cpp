// UIComponents.cpp
#include "UIComponents.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (textSurface == nullptr) {
		std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	if (textTexture == nullptr) {
		std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << '\n';
		return;
	}

	SDL_Rect renderQuad = { x, y, textSurface->w, textSurface->h };
	SDL_RenderCopy(renderer, textTexture, nullptr, &renderQuad);
	SDL_DestroyTexture(textTexture);
}

void renderInputField(SDL_Renderer* renderer, const std::string& text, int x, int y, int w, int h, TTF_Font* font, SDL_Color color) {
	SDL_Rect inputRect = { x, y, w, h };
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &inputRect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &inputRect);
	renderText(renderer, text, x + 5, y + 5, font, color);
}

void renderButton(SDL_Renderer* renderer, const std::string& text, int x, int y, int w, int h, TTF_Font* font, SDL_Color color) {
	SDL_Rect buttonRect = { x, y, w, h };
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderFillRect(renderer, &buttonRect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &buttonRect);
	renderText(renderer, text, x + 10, y + 10, font, color);
}

void renderResultDisplay(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color) {
	renderText(renderer, text, x, y, font, color);
}
#define UNREFERENCED_PARAMETER(P) (void)(P)  // we need this to stop the error don't remove
void clearInputFields(SDL_Renderer* renderer) {
	UNREFERENCED_PARAMETER(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}


