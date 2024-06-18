#include "Page9.h"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"

void displayPage9() {
	std::cout << "\033[2J\033[1;1H"; // Clear screen (optional)

	std::vector<std::string> names;
	std::string name;

	std::cout << "Enter names (type 'done' to finish):" << std::endl;
	while (true) {
		std::cout << "Name: ";
		std::getline(std::cin, name);
		if (name == "done") {
			break;
		}
		names.push_back(name);
	}

	std::cout << "You entered the following names:" << std::endl;
	for (const auto& n : names) {
		std::cout << n << std::endl;
	}
}

// Register the page with the menu system
bool registerPage9 = (registerPage("9", "Practice_1", displayPage9, 9), true);
