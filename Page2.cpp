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
	std::vector<double> vec1 = readVector();
	std::vector<double> vec2 = readVector();
	std::vector<double> result(3);
	std::string resultText = "Result: ";

	for (int i = 0; i < 3; ++i) {
		result[i] = vec1[i] + vec2[i];
		resultText += std::to_string(result[i]) + " ";
	}

	TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}
	SDL_Color textColor = { 0, 0, 0, 255 };

	renderResultDisplay(renderer, resultText, 50, 470, font, textColor);
	TTF_CloseFont(font);
}

// Function for vector subtraction
void vectorSubtraction(SDL_Renderer* renderer) {
	std::vector<double> vec1 = readVector();
	std::vector<double> vec2 = readVector();
	std::vector<double> result(3);
	std::string resultText = "Result: ";

	for (int i = 0; i < 3; ++i) {
		result[i] = vec1[i] - vec2[i];
		resultText += std::to_string(result[i]) + " ";
	}

	TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}
	SDL_Color textColor = { 0, 0, 0, 255 };

	renderResultDisplay(renderer, resultText, 50, 470, font, textColor);
	TTF_CloseFont(font);
}

// Function for dot product
void dotProduct(SDL_Renderer* renderer) {
	std::vector<double> vec1 = readVector();
	std::vector<double> vec2 = readVector();
	double result = 0;
	std::string resultText = "Dot Product: ";

	for (int i = 0; i < 3; ++i) {
		result += vec1[i] * vec2[i];
	}
	resultText += std::to_string(result);

	TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}
	SDL_Color textColor = { 0, 0, 0, 255 };

	renderResultDisplay(renderer, resultText, 50, 470, font, textColor);
	TTF_CloseFont(font);
}

// Function for cross product
void crossProduct(SDL_Renderer* renderer) {
	std::vector<double> vec1 = readVector();
	std::vector<double> vec2 = readVector();
	std::vector<double> result(3);
	std::string resultText = "Cross Product: ";

	result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
	result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
	result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];

	resultText += "(" + std::to_string(result[0]) + ", " + std::to_string(result[1]) + ", " + std::to_string(result[2]) + ")";

	TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}
	SDL_Color textColor = { 0, 0, 0, 255 };

	renderResultDisplay(renderer, resultText, 50, 470, font, textColor);
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
