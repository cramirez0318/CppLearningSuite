#include "Page13.h"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"



// full implementation of the getUserInput Function


int getUserInput()
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

char getMathematicalOperation()
{
	std:: cout << "Enter an operation (+, -, *, /): ";
	char operation{};
	std::cin >> operation;

	return operation;
}

int getUserInput2()
{
	std::cout << "Enter the 2nd integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int calculateResult(int value1, char operation, int value2)
{

	int result{};

	switch (operation)
	{
	case '+':
		result = value1 + value2;
		break;
	case '-':
		result = value1 - value2;
		break;
	case '*':
		result = value1 * value2;
		break;
	case '/':
		if (value2 != 0)
			result = value1 / value2;
		else
		{
			std::cerr << "Error: Division by Zero!\n";
			result = 0; 
		}
		break;
	default:
		std::cerr << "Error: Invalid operation!\n";
		result = 0;
		break;
	}

	return result;

}


void displayPage13()
{

	// Get first number from user
	int value1{ getUserInput()};
	std:: cout << value1 << '\n';


	// Get mathematical operation from user
	char operation{ getMathematicalOperation() };
	std:: cout << operation << '\n';

	// Get second number from user
	int value2{ getUserInput2()};
	std:: cout << value2 << '\n';

	// Calculate result
	int result = calculateResult(value1, operation, value2);

	// Print result
	std::cout << "The result is:" << result << '\n';



}

// Register the page with the menu system
bool registerPage13 = (registerPage("13", "Practice_5", displayPage13, 13), true);