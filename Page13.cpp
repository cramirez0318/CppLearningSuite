#include "Page13.h"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"



void doIt(int x)
{
	int y{ 4 };
	std::cout << "doIt: x = " << x << " y  = " << y << '\n';

	x = 3;
	std::cout << "doIt: x = " << x << " y = " << y << '\n';
}


void displayPage13()
{
	int x{1};
	int y{2};

	std::cout << "main: x = " << x << " y = " << y << '\n';

	doIt(x);

	std::cout << "main: x = " << x << " y = " << y << '\n';
}

// Register the page with the menu system
bool registerPage13 = (registerPage("13", "Practice_5", displayPage13, 13), true);