#include "Page1.h"
#include "Constants.h"
#include <iostream>
#include <limits>
#include "Menu.h"
#include "graphics/MenuGraphics.h"

void simpleCalculator(SDL_Renderer* renderer) {
    double num1 = 0, num2 = 0;
    char operation = '+';
    std::string result = "";
    bool validInput = true;

    TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
    if (font == nullptr) {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
        return;
    }

    SDL_Color textColor = { 0, 0, 0, 255 };

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_TEXTINPUT) {
                // Handle text input for input fields
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                // Handle button clicks
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        renderInputField(renderer, std::to_string(num1), 50, 50, 200, 50, font, textColor);
        renderInputField(renderer, std::string(1, operation), 50, 110, 50, 50, font, textColor);
        renderInputField(renderer, std::to_string(num2), 50, 170, 200, 50, font, textColor);
        renderButton(renderer, "Calculate", 50, 230, 200, 50, font, textColor);
        renderResultDisplay(renderer, result, 50, 290, font, textColor);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
}

void displayPage1(SDL_Renderer* renderer) {
    simpleCalculator(renderer);
}

// Register the page with the menu system
bool registerPage1 = (registerPage("1", "Simple Calculator", []() { displayPage1(nullptr); }, 1), true);
