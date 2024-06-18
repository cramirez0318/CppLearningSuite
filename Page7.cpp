#include "Page7.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Menu.h"


void displayPage7() {
	char continueInput = 'y';

	while (continueInput == 'y' || continueInput == 'Y') {
		int x {};
		int y {};

		std::cout << "Enter an integer: ";
		std::cin >> x;

		std::cout << "Enter another integer: ";
		std::cin >> y;

		std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;
		std::cout << "The difference between " << x << " and " << y << " is " << x - y << std::endl;

		std::cout << "Would you like to enter another set of integers? (y/n): ";
		std::cin >> continueInput;
	}
}

// Register the page with the menu system
bool registerPage7 = (registerPage("7", "WildLoop", displayPage7, 7), true);