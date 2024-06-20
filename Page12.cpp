#include "Page12.h"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"



int add(int x, int y, const std::string& str, bool flag)
{
	int sum = x + y;
	std::cout << "String argument: " << str << std::endl;
	if (flag)
	{
		std::cout << "Flag is true, doubling the sum." << std::endl;
		sum *= 2;
	}
	return sum;
}



void displayPage12()
{
	int a, b;
	std::string str;
	bool flag;

	std::cout << "Enter two numbers: ";
	std::cin >> a >> b;
	std::cin.ignore();

	std::cout << "Enter a string: ";
	std::getline(std::cin, str);

	std::cout << "Enter a boolean value (0 or 1): ";
	std::cin >> flag;

	int result = add(a, b, str, flag);
	std::cout << "The result is: " << result << std::endl;
}

// Register the page with the menu system
bool registerPage12 = (registerPage("12", "Practice_4", displayPage12, 12), true);