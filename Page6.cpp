#include "Page6.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Menu.h"

int five()
 {
	return 5;
}

void displayPage6() {

	int a{ 2 };             // initialize variable a with literal value 2
	int b{ 2 + 3 };         // initialize variable b with computed value 5
	int c{ (2 * 3) + 4 };   // initialize variable c with computed value 10
	int d{ b };             // initialize variable d with variable value 5
	int e{ five() };        // initialize variable e with function return value 5

	// Additional code to use the variables, otherwise they might be optimized away
	std::cout << "a: " << a << "\n";
	std::cout << "b: " << b << "\n";
	std::cout << "c: " << c << "\n";
	std::cout << "d: " << d << "\n";
	std::cout << "e: " << e << "\n";

	// New code from the given program
	std::cout << 2 + 3 << '\n';
	int x{ 6 };
	int y{ x - 2 };
	std::cout << y << '\n';
	int z{ };
	z = x;
	std::cout << z * x << '\n';
}

// Register the page with the menu system
bool registerPage6 = (registerPage("6", "TestPrint", displayPage6, 6), true);