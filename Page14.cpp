#include "Page14.h"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include"io.h"




void displayPage14()
{
	int result{ readNumber() };
	writeAnswer(result);
}




// Register the page with the menu system
bool registerPage14 = (registerPage("14", "Practice_6", displayPage14, 14), true);