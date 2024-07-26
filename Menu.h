#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <string>
#include <SDL.h>

void displayMainMenu(SDL_Renderer* renderer);
void handleMainMenuChoice(SDL_Event& e);
void registerPage(const std::string& key, const std::string& name, const std::function<void()>& func, int order);

using MenuFunction = std::function<void()>;
extern std::unordered_map<std::string, MenuFunction> menuOptions;
extern std::unordered_map<std::string, std::string> menuNames;
extern std::vector<std::pair<int, std::string>> menuOrder;
