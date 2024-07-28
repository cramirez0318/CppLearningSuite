#include "Page2.h"
#include "Constants.h"
#include <iostream>
#include <vector>
#include "Menu.h"
#include "graphics/MenuGraphics.h"

// Function to read a vector from the user
std::vector<double> readVector() {
    std::vector<double> vec(3);
    std::cout << "Enter vector (3 components): ";
    std::cin >> vec[0] >> vec[1] >> vec[2];
    return vec;
}

// Function to print a vector
void printVector(const std::vector<double>& vec) {
    std::cout << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")\n";
}

// Function for vector addition
void vectorAddition(SDL_Renderer* renderer) {
    std::vector<double> vec1(3), vec2(3), result(3);
    std::string resultText = "";
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
        renderInputField(renderer, std::to_string(vec1[0]), 50, 50, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec1[1]), 50, 110, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec1[2]), 50, 170, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[0]), 50, 230, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[1]), 50, 290, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[2]), 50, 350, 200, 50, font, textColor);
        renderButton(renderer, "Add", 50, 410, 200, 50, font, textColor);
        renderResultDisplay(renderer, resultText, 50, 470, font, textColor);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
}

// Function for vector subtraction
void vectorSubtraction(SDL_Renderer* renderer) {
    std::vector<double> vec1(3), vec2(3), result(3);
    std::string resultText = "";
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
        renderInputField(renderer, std::to_string(vec1[0]), 50, 50, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec1[1]), 50, 110, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec1[2]), 50, 170, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[0]), 50, 230, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[1]), 50, 290, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[2]), 50, 350, 200, 50, font, textColor);
        renderButton(renderer, "Subtract", 50, 410, 200, 50, font, textColor);
        renderResultDisplay(renderer, resultText, 50, 470, font, textColor);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
}

// Function for dot product
void dotProduct(SDL_Renderer* renderer) {
    std::vector<double> vec1(3), vec2(3);
    double result = 0;
    std::string resultText = "";
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
        renderInputField(renderer, std::to_string(vec1[0]), 50, 50, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec1[1]), 50, 110, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec1[2]), 50, 170, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[0]), 50, 230, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[1]), 50, 290, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[2]), 50, 350, 200, 50, font, textColor);
        renderButton(renderer, "Dot Product", 50, 410, 200, 50, font, textColor);
        renderResultDisplay(renderer, resultText, 50, 470, font, textColor);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
}

// Function for cross product
void crossProduct(SDL_Renderer* renderer) {
    std::vector<double> vec1(3), vec2(3), result(3);
    std::string resultText = "";
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
        renderInputField(renderer, std::to_string(vec1[0]), 50, 50, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec1[1]), 50, 110, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec1[2]), 50, 170, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[0]), 50, 230, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[1]), 50, 290, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(vec2[2]), 50, 350, 200, 50, font, textColor);
        renderButton(renderer, "Cross Product", 50, 410, 200, 50, font, textColor);
        renderResultDisplay(renderer, resultText, 50, 470, font, textColor);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
}

// Display Page 2 menu
void displayPage2(SDL_Renderer* renderer) {
    int choice;
    do {
        std::cout << "Vector Calculator:\n";
        std::cout << "1. Add Vectors\n";
        std::cout << "2. Subtract Vectors\n";
        std::cout << "3. Dot Product\n";
        std::cout << "4. Cross Product\n";
        std::cout << RETURN_TO_MAIN_MENU << ". Return to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            vectorAddition(renderer);
            break;
        case 2:
            vectorSubtraction(renderer);
            break;
        case 3:
            dotProduct(renderer);
            break;
        case 4:
            crossProduct(renderer);
            break;
        case RETURN_TO_MAIN_MENU:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        if (choice != RETURN_TO_MAIN_MENU) {
            std::cout << "Press Enter to return to the Vector Calculator menu.\n";
            std::cin.ignore();
            std::cin.get();
        }
    } while (choice != RETURN_TO_MAIN_MENU);
}

// Register the page with the menu system
bool registerPage2 = (registerPage("2", "Vector Calculator", []() { displayPage2(nullptr); }, 2), true);
