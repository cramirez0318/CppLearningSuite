#pragma once
#include <unordered_map>
#include <functional>
#include <string>

void displayMainMenu();
void handleMainMenuChoice(char choice);
void registerPage(char key, const std::string& name, std::function<void()> func);

using MenuFunction = std::function<void()>;
extern std::unordered_map<char, MenuFunction> menuOptions;
extern std::unordered_map<char, std::string> menuNames;