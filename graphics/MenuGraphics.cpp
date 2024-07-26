#include "MenuGraphics.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <unordered_map>
#include <vector>

bool initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not initialize! TTF_Error: " << TTF_GetError() << std::endl;
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
        std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == nullptr) {
        std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        return;
    }

    SDL_Rect renderQuad = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, textTexture, nullptr, &renderQuad);

    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}

void renderMainMenu(SDL_Renderer* renderer, const std::vector<std::pair<int, std::string>>& menuOrder, const std::unordered_map<std::string, std::string>& menuNames) {
    TTF_Font* font = TTF_OpenFont("arial.ttf", 28);
    if (font == nullptr) {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Color textColor = { 0, 0, 0, 255 };
    int y = 50;

    for (const auto& item : menuOrder) {
        renderText(renderer, menuNames.at(item.second), 50, y, font, textColor);
        y += 50;
    }

    TTF_CloseFont(font);
}

void handleMenuEvent(SDL_Event& e, std::unordered_map<std::string, MenuFunction>& menuOptions) {
    if (e.type == SDL_KEYDOWN) {
        std::string choice(1, static_cast<char>(e.key.keysym.sym));
        auto it = menuOptions.find(choice);
        if (it != menuOptions.end()) {
            it->second();
        }
    }
}