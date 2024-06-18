#include "Menu.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

std::unordered_map<std::string, MenuFunction> menuOptions;
std::unordered_map<std::string, std::string> menuNames;
std::vector<std::pair<int, std::string>> menuOrder;

void registerPage(const std::string& key, const std::string& name, const std::function<void()>& func, int order) {
	menuOptions[key] = func;
	menuNames[key] = name;
	menuOrder.emplace_back(order, key);
	std::ranges::sort(menuOrder.begin(), menuOrder.end());
}

void displayMainMenu() {
	std::cout << "Main Menu:\n";
	for (const auto& entry : menuOrder) {
		std::cout << entry.second << ". " << menuNames[entry.second] << "\n";
	}
	std::cout << "e. Exit\n";
	std::cout << "Enter your choice: ";
}

void handleMainMenuChoice(const std::string& choice) {
	auto it = menuOptions.find(choice);
	if (it != menuOptions.end()) {
		it->second();
	}
	else if (choice == "e") {
		std::cout << "Exiting...\n";
	}
	else {
		std::cout << "Invalid choice. Please try again.\n";
	}
}
