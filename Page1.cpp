#include "Page1.h"
#include "Constants.h"
#include <iostream>
#include <limits>
#include "Menu.h"

void simpleCalculator() {
	double num1, num2;
	char operation;

	std::cout << "Enter first number: ";
	while (!(std::cin >> num1)) {
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		std::cout << "Invalid input. Please enter a number: ";
	}

	std::cout << "Enter an operator (+, -, *, /): ";
	std::cin >> operation;

	std::cout << "Enter second number: ";
	while (!(std::cin >> num2)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a number: ";
	}

	switch (operation) {
	case '+':
		std::cout << "Result: " << num1 + num2 << "\n";
		break;
	case '-':
		std::cout << "Result: " << num1 - num2 << "\n";
		break;
	case '*':
		std::cout << "Result: " << num1 * num2 << "\n";
		break;
	case '/':
		if (num2 != 0)
			std::cout << "Result: " << num1 / num2 << "\n";
		else
			std::cout << "Error: Division by zero!\n";
		break;
	default:
		std::cout << "Invalid operator!\n";
		break;
	}
}

void displayPage1() {
	int choice;
	do {
		std::cout << "Simple Calculator:\n";
		std::cout << "1. Perform a calculation\n";
		std::cout << RETURN_TO_MAIN_MENU << ". Return to Main Menu\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			simpleCalculator();
			break;
		case RETURN_TO_MAIN_MENU:
			std::cout << "Returning to main menu...\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}

		if (choice != RETURN_TO_MAIN_MENU) {
			std::cout << "Press Enter to return to the Simple Calculator menu.\n";
			std::cin.ignore();
			std::cin.get();
		}
	} while (choice != RETURN_TO_MAIN_MENU);
}

// Register the page with the menu system
bool registerPage1 = (registerPage("1", "Simple Calculator", displayPage1, 1), true);
