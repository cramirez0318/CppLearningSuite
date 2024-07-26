#include "Page16.h"
#include <iostream>
#include "Menu.h"


int getValue()
{
	return 4;
}


void displayPage16()
{

	std::cout << getValue() << '\n';


}



// Register the page with the menu system
bool registerPage16 = (registerPage("16", "Errors-2", displayPage16, 16), true);