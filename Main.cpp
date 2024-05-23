#include "Menu.h"
#include <iostream>

int main() {
	char choice;
	do {
		displayMainMenu();
		std::cin >> choice;
		handleMainMenuChoice(choice);
	} while (choice != 'e');

	return 0;
}
