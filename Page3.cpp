#include "Page3.h"
#include "Constants.h"
#include <iostream>
#include <vector>
#include "Menu.h"
#include "graphics/MenuGraphics.h"

using Matrix = std::vector<std::vector<double>>;

// Function to read a 2x2 matrix from the user
Matrix readMatrix() {
    Matrix mat(2, std::vector<double>(2));
    std::cout << "Enter matrix (2x2 components): \n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cin >> mat[i][j];
        }
    }
    return mat;
}

// Function to print a 2x2 matrix
void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        std::cout << "(" << row[0] << ", " << row[1] << ")\n";
    }
}

// Function for matrix addition
void matrixAddition(SDL_Renderer* renderer) {
    Matrix mat1(2, std::vector<double>(2)), mat2(2, std::vector<double>(2)), result(2, std::vector<double>(2));
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
        renderInputField(renderer, std::to_string(mat1[0][0]), 50, 50, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[0][1]), 50, 110, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[1][0]), 50, 170, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[1][1]), 50, 230, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[0][0]), 50, 290, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[0][1]), 50, 350, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[1][0]), 50, 410, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[1][1]), 50, 470, 200, 50, font, textColor);
        renderButton(renderer, "Add", 50, 530, 200, 50, font, textColor);
        renderResultDisplay(renderer, resultText, 50, 590, font, textColor);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
}

// Function for matrix subtraction
void matrixSubtraction(SDL_Renderer* renderer) {
    Matrix mat1(2, std::vector<double>(2)), mat2(2, std::vector<double>(2)), result(2, std::vector<double>(2));
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
        renderInputField(renderer, std::to_string(mat1[0][0]), 50, 50, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[0][1]), 50, 110, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[1][0]), 50, 170, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[1][1]), 50, 230, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[0][0]), 50, 290, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[0][1]), 50, 350, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[1][0]), 50, 410, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[1][1]), 50, 470, 200, 50, font, textColor);
        renderButton(renderer, "Subtract", 50, 530, 200, 50, font, textColor);
        renderResultDisplay(renderer, resultText, 50, 590, font, textColor);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
}

// Function for matrix multiplication
void matrixMultiplication(SDL_Renderer* renderer) {
    Matrix mat1(2, std::vector<double>(2)), mat2(2, std::vector<double>(2)), result(2, std::vector<double>(2));
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
        renderInputField(renderer, std::to_string(mat1[0][0]), 50, 50, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[0][1]), 50, 110, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[1][0]), 50, 170, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat1[1][1]), 50, 230, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[0][0]), 50, 290, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[0][1]), 50, 350, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[1][0]), 50, 410, 200, 50, font, textColor);
        renderInputField(renderer, std::to_string(mat2[1][1]), 50, 470, 200, 50, font, textColor);
        renderButton(renderer, "Multiply", 50, 530, 200, 50, font, textColor);
        renderResultDisplay(renderer, resultText, 50, 590, font, textColor);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
}

// Function to clear input fields
void clearInputFields(SDL_Renderer* renderer) {
    // Implement logic to clear input fields
}

// Display Page 3 menu
void displayPage3(SDL_Renderer* renderer) {
    int choice;
    do {
        std::cout << "Matrix Calculator:\n";
        std::cout << "1. Add Matrices\n";
        std::cout << "2. Subtract Matrices\n";
        std::cout << "3. Multiply Matrices\n";
        std::cout << "4. Clear Input Fields\n";
        std::cout << RETURN_TO_MAIN_MENU << ". Return to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            matrixAddition(renderer);
            break;
        case 2:
            matrixSubtraction(renderer);
            break;
        case 3:
            matrixMultiplication(renderer);
            break;
        case 4:
            clearInputFields(renderer);
            break;
        case RETURN_TO_MAIN_MENU:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        if (choice != RETURN_TO_MAIN_MENU) {
            std::cout << "Press Enter to return to the Matrix Calculator menu.\n";
            std::cin.ignore();
            std::cin.get();
        }
    } while (choice != RETURN_TO_MAIN_MENU);
}

// Register the page with the menu system
bool registerPage3 = (registerPage("3", "Matrix Calculator", []() { displayPage3(nullptr); }, 3), true);
