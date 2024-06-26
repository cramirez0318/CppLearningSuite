#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <string>

void displayMainMenu();
void handleMainMenuChoice(const std::string& choice);
void registerPage(const std::string& key, const std::string& name, const std::function<void()>& func, int order);

using MenuFunction = std::function<void()>;
extern std::unordered_map<std::string, MenuFunction> menuOptions;
extern std::unordered_map<std::string, std::string> menuNames;
extern std::vector<std::pair<int, std::string>> menuOrder;
