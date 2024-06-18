#include "Page2.h"
#include"Constants.h"
#include <iostream>
#include <vector>
#include "Menu.h"

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
void vectorAddition() {
	std::cout << "Vector Addition:\n";
	auto vec1 = readVector();
	auto vec2 = readVector();
	std::vector<double> result(3);
	for (int i = 0; i < 3; ++i) {
		result[i] = vec1[i] + vec2[i];
	}
	std::cout << "Result: ";
	printVector(result);
}

// Function for vector subtraction
void vectorSubtraction() {
	std::cout << "Vector Subtraction:\n";
	auto vec1 = readVector();
	auto vec2 = readVector();
	std::vector<double> result(3);
	for (int i = 0; i < 3; ++i) {
		result[i] = vec1[i] - vec2[i];
	}
	std::cout << "Result: ";
	printVector(result);
}

// Function for dot product
void dotProduct() {
	std::cout << "Dot Product:\n";
	auto vec1 = readVector();
	auto vec2 = readVector();
	double result = 0;
	for (int i = 0; i < 3; ++i) {
		result += vec1[i] * vec2[i];
	}
	std::cout << "Result: " << result << "\n";
}

// Function for cross product
void crossProduct() {
	std::cout << "Cross Product:\n";
	auto vec1 = readVector();
	auto vec2 = readVector();
	std::vector<double> result(3);
	result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
	result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
	result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
	std::cout << "Result: ";
	printVector(result);
}

// Display Page 2 menu
void displayPage2() {
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
			vectorAddition();
			break;
		case 2:
			vectorSubtraction();
			break;
		case 3:
			dotProduct();
			break;
		case 4:
			crossProduct();
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
bool registerPage2 = (registerPage("2", "Vector Calculator", displayPage2, 2), true);