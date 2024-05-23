#include "Page4.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Menu.h"

void displayPage4() {
	std::cout << "Enter a number: ";
	std::string input;
	int x;

	while (true) {
		std::getline(std::cin, input);
		std::stringstream ss(input);

		if (ss >> x) {
			// Check if the entire string was a valid integer
			char remaining;
			if (ss >> remaining) {
				std::cout << "Invalid input: " << input << ". Please enter a number: ";
			}
			else {
				break;
			}
		}
		else {
			std::cout << "Invalid input: " << input << ". Please enter a number: ";
		}
	}

	std::cout << "You entered: " << x << '\n';
}

// Register the page with the menu system
bool registerPage4 = (registerPage('4', "Number Enter Print", displayPage4), true);