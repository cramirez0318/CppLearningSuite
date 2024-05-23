#include "Menu.h"
#include <iostream>

std::unordered_map<char, MenuFunction> menuOptions;
std::unordered_map<char, std::string> menuNames;

void registerPage(char key, const std::string& name, MenuFunction func) {
	menuOptions[key] = func;
	menuNames[key] = name;
}

void displayMainMenu() {
	std::cout << "Main Menu:\n";
	for (const auto& entry : menuNames) {
		std::cout << entry.first << ". " << entry.second << "\n";
	}
	std::cout << "e. Exit\n";
	std::cout << "Enter your choice: ";
}

void handleMainMenuChoice(char choice) {
	auto it = menuOptions.find(choice);
	if (it != menuOptions.end()) {
		it->second();  
	}
	else if (choice == 'e') {
		std::cout << "Exiting...\n";
	}
	else {
		std::cout << "Invalid choice. Please try again.\n";
	}
}
