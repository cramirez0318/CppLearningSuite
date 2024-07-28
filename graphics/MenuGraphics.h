#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <unordered_map>
#include <vector>
#include <string>
#include "../Menu.h"

bool initSDL();
void closeSDL();
void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color);
void renderMainMenu(SDL_Renderer* renderer, const std::vector<std::pair<int, std::string>>& menuOrder, const std::unordered_map<std::string, std::string>& localmenuNames);
void handleMenuEvent(SDL_Event& e, std::unordered_map<std::string, MenuFunction>& localMenuOptions);

