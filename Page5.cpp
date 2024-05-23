#include "Page5.h"
#include "Menu.h"
#include <iostream>

void displayPage5() {

	std::cout << sizeof(int) << '\n';

}

// Register the page with the menu system
bool registerPage5 = (registerPage('5', "FreePage", displayPage5), true);
