#include "Page8.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Menu.h"


int getValueFromUser()
{
	std::cout << "Enter an integer:";
	int input{};
	std::cin >> input;

	return input;
}

void displayPage8() {

	int x { getValueFromUser() };
	int y { getValueFromUser() };

	std::cout<< x << " + " << y << " = " << x + y << '\n';

	
}

// Register the page with the menu system
bool registerPage8 = (registerPage("8", "Function", displayPage8, 8), true);