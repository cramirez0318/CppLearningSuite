#include "Page11.h"
#include <iostream>
#include <vector>
#include "Menu.h"


int doubleNumber(int X)
{
		return X * 2;
}



void displayPage11()
{
	int X{};

	std::cout << "Enter a number: ";
	std::cin >> X;
	std::cout << "The Double the number is: " << doubleNumber(X) << std::endl;




}

// Register the page with the menu system
bool registerPage11 = (registerPage("11", "Practice_3", displayPage11, 11), true);