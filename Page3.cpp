#include "Page3.h"
#include "Constants.h"
#include <iostream>
#include <vector>
#include "Menu.h"
#include "UIComponents.h"

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

void matrixAddition(SDL_Renderer* renderer) {
	Matrix mat1 = readMatrix();
	Matrix mat2 = readMatrix();
	Matrix result(2, std::vector<double>(2));

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			result[i][j] = mat1[i][j] + mat2[i][j];
		}
	}

	std::string resultText = "Result:\n";
	for (const auto& row : result) {
		resultText += "(" + std::to_string(row[0]) + ", " + std::to_string(row[1]) + ")\n";
	}

	TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}
	SDL_Color textColor = { 0, 0, 0, 255 };

	renderResultDisplay(renderer, resultText, 50, 590, font, textColor);
	TTF_CloseFont(font);
}

void matrixSubtraction(SDL_Renderer* renderer) {
	Matrix mat1 = readMatrix();
	Matrix mat2 = readMatrix();
	Matrix result(2, std::vector<double>(2));

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			result[i][j] = mat1[i][j] - mat2[i][j];
		}
	}

	std::string resultText = "Result:\n";
	for (const auto& row : result) {
		resultText += "(" + std::to_string(row[0]) + ", " + std::to_string(row[1]) + ")\n";
	}

	TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}
	SDL_Color textColor = { 0, 0, 0, 255 };

	renderResultDisplay(renderer, resultText, 50, 590, font, textColor);
	TTF_CloseFont(font);
}

void matrixMultiplication(SDL_Renderer* renderer) {
	Matrix mat1 = readMatrix();
	Matrix mat2 = readMatrix();
	Matrix result(2, std::vector<double>(2));

	result[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
	result[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
	result[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
	result[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];

	std::string resultText = "Result:\n";
	for (const auto& row : result) {
		resultText += "(" + std::to_string(row[0]) + ", " + std::to_string(row[1]) + ")\n";
	}

	TTF_Font* font = TTF_OpenFont(R"(C:\Users\chris\source\repos\CPP_Learning\Fonts\arial.ttf)", 28);
	if (font == nullptr) {
		std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << '\n';
		return;
	}
	SDL_Color textColor = { 0, 0, 0, 255 };

	renderResultDisplay(renderer, resultText, 50, 590, font, textColor);
	TTF_CloseFont(font);
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
