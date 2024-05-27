#include "Page5.h"
#include "Menu.h"
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

namespace py = pybind11;

void displayPage5() {
	py::scoped_interpreter guard{}; // Start the interpreter and keep it alive

	try {
		py::module db = py::module::import("database");

		// Add a character to the database
		db.attr("add_character")("John Doe", 30, "Strength:10, Intelligence:8");

		// Retrieve a character from the database
		py::object character = db.attr("get_character")(1);
		if (!character.is_none()) {
			std::cout << "Character Name: " << character.attr("name").cast<std::string>() << "\n";
			std::cout << "Character Age: " << character.attr("age").cast<int>() << "\n";
			std::cout << "Character Attributes: " << character.attr("attributes").cast<std::string>() << "\n";
		}
		else {
			std::cout << "Character not found.\n";
		}

		// Retrieve all characters from the database
		py::list characters = db.attr("get_all_characters")();
		for (auto char_obj : characters) {
			std::cout << "Character Name: " << char_obj.attr("name").cast<std::string>() << "\n";
			std::cout << "Character Age: " << char_obj.attr("age").cast<int>() << "\n";
			std::cout << "Character Attributes: " << char_obj.attr("attributes").cast<std::string>() << "\n";
		}
	}
	catch (py::error_already_set& e) {
		std::cerr << "Python error: " << e.what() << std::endl;
	}
}

// Register the page with the menu system
bool registerPage5 = (registerPage('5', "FreePage", displayPage5), true);
