#pragma once
#include <SDL.h>
#include <unordered_map>
#include <string>


// These files will handle the interaction logic, such as capturing input and updating states for different pages.

void handleCalculatorEvent(SDL_Event& e, std::unordered_map<std::string, std::string>& inputFields, std::string& result);
// Other page-specific interaction functions...
