#include "Page10.h"
#include <iostream>
#include <vector>
#include "Menu.h"

void vectorMatrix() {
	std::vector<std::vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
}

void displayPage10() {
	std::vector<std::vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	int* p1, * p2, * p3, * p4;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			p1 = &matrix[i][j];
			p2 = &matrix[i][(j + 1) % 4];
			p3 = &matrix[(i + 1) % 4][j];
			p4 = &matrix[(i + 1) % 4][(j + 1) % 4];

			std::cout << "Pointers at (" << i << "," << j << "): "
				<< *p1 << " " << *p2 << " " << *p3 << " " << *p4 << std::endl;
		}
	}
}

// Register the page with the menu system
bool registerPage10 = (registerPage("10", "Practice_2", displayPage10, 10), true);
