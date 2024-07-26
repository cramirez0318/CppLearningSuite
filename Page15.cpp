#include "Page15.h"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include <algorithm>


void getNames(std::vector<std::string>& names)
{
	std::string name;
	while (true)
	{
		std::cout << "Enter a name (or 'done' to finish): ";
		std::getline(std::cin, name);

		if (name == "done")
			break;

		names.push_back(name);
	}
}

void sortNames(std::vector<std::string>& names)
{
	std::sort(names.begin(), names.end());
}

void printNames(const std::vector<std::string>& names)
{
	std::cout << "Sorted names:\n";
	for (const auto& name : names)
	{
		std::cout << name << '\n';
	}
}

void displayPage15()
{
	std::vector<std::string> names;
	getNames(names); // ask user to enter a bunch of names
	sortNames(names); // sort them in alphabetical order
	printNames(names); // print the sorted list of names
}

// Register the page with the menu system
bool registerPage15 = (registerPage("15", "Errors", displayPage15, 15), true);