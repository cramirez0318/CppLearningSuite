#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <unordered_map>
#include <vector>
#include <string>
#include "../Menu.h"

// SDL Initialization and Shutdown
bool initSDL();
void closeSDL();

// Text Rendering
void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color);

// Menu Rendering and Event Handling
void renderMainMenu(SDL_Renderer* renderer, const std::vector<std::pair<int, std::string>>& menuOrder, const std::unordered_map<std::string, std::string>& localmenuNames);
void handleMenuEvent(SDL_Event& e, std::unordered_map<std::string, MenuFunction>& localMenuOptions);

// UI Components
void renderInputField(SDL_Renderer* renderer, const std::string& text, int x, int y, int w, int h, TTF_Font* font, SDL_Color color);
void renderButton(SDL_Renderer* renderer, const std::string& text, int x, int y, int w, int h, TTF_Font* font, SDL_Color color);
void renderResultDisplay(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color);
void clearInputFields(SDL_Renderer* renderer);



