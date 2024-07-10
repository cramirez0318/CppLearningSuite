#include "io.h"
#include <iostream>

int readNumber()
{
	std::cout << "Enter two numbers separated by a space: ";
	int x{}, y{};
	std::cin >> x >> y;
	return x + y;
}

void writeAnswer(int result)
{
	std::cout << "The result is: " << result << '\n';
}
