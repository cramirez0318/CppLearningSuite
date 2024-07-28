#include "Menu.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <SDL.h>
#include "graphics/MenuGraphics.h"
#include <pybind11/embed.h>

namespace py = pybind11;

std::unordered_map<std::string, MenuFunction> menuOptions;
std::unordered_map<std::string, std::string> menuNames;
std::vector<std::pair<int, std::string>> menuOrder;

void registerPage(const std::string& key, const std::string& name, const std::function<void()>& func, int order) {
	menuOptions[key] = func;
	menuNames[key] = name;
	menuOrder.emplace_back(order, key);
	std::ranges::sort(menuOrder.begin(), menuOrder.end());
}

void displayMainMenu(SDL_Renderer* renderer) {
	renderMainMenu(renderer, menuOrder, menuNames);
}

void handle_key_input(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_u) {
            py::exec("undo_action()");
        } else if (event.key.keysym.sym == SDLK_r) {
            py::exec("redo_action()");
        }
    }
}

void handleMainMenuChoice(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN) {
		std::string choice(1, static_cast<char>(e.key.keysym.sym));
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
		handle_key_input(e);
	}
}

// Function to bind user inputs to variables used in calculations
void bindUserInputs(std::unordered_map<std::string, std::string>& inputFields, std::string& result) {
	// Implement binding logic here
}
