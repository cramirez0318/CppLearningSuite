#include "Menu.h"
#include <iostream>
#include <cstdlib>

int main() {
	std::string choice;
	do {
		displayMainMenu();
		std::cin >> choice;
		handleMainMenuChoice(choice);
	} while (choice != "e");

	return EXIT_SUCCESS;
}
