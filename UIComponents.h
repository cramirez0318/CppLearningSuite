#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

// This file will contain all the UI-related functions such as rendering text, buttons, input fields, and handling input clearing.

void renderInputField(SDL_Renderer* renderer, const std::string& text, int x, int y, int w, int h, TTF_Font* font, SDL_Color color);
void renderButton(SDL_Renderer* renderer, const std::string& text, int x, int y, int w, int h, TTF_Font* font, SDL_Color color);
void renderResultDisplay(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color);
void clearInputFields(SDL_Renderer* renderer);
