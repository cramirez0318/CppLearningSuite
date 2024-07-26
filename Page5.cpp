#include "Page5.h"
#include "Menu.h"
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

namespace py = pybind11;

void addCharacter() {
    std::string name, attributes;
    int age, parent_id;

    std::cout << "Enter character name: ";
    std::cin >> name;
    std::cout << "Enter character age: ";
    std::cin >> age;
    std::cout << "Enter character attributes: ";
    std::cin >> attributes;
    std::cout << "Enter parent ID (or -1 if none): ";
    std::cin >> parent_id;

    py::module db = py::module::import("database");
    db.attr("add_character")(name, age, attributes, parent_id == -1 ? py::none() : py::int_(parent_id));
}

void getCharacter() {
    int id;
    std::cout << "Enter character ID: ";
    std::cin >> id;

    py::module db = py::module::import("database");
    py::object character = db.attr("get_character")(id);
    if (!character.is_none()) {
        std::cout << "Character Name: " << character.attr("name").cast<std::string>() << "\n";
        std::cout << "Character Age: " << character.attr("age").cast<int>() << "\n";
        std::cout << "Character Attributes: " << character.attr("attributes").cast<std::string>() << "\n";
    } else {
        std::cout << "Character not found.\n";
    }
}

void getAllCharacters() {
    py::module db = py::module::import("database");
    py::list characters = db.attr("get_all_characters")();
    for (auto char_obj : characters) {
        std::cout << "Character Name: " << char_obj.attr("name").cast<std::string>() << "\n";
        std::cout << "Character Age: " << char_obj.attr("age").cast<int>() << "\n";
        std::cout << "Character Attributes: " << char_obj.attr("attributes").cast<std::string>() << "\n";
    }
}

void displayPage5() {
    py::scoped_interpreter guard{}; // Start the interpreter and keep it alive

    int choice;
    do {
        std::cout << "Python Database Interaction:\n";
        std::cout << "1. Add a character\n";
        std::cout << "2. Get a character by ID\n";
        std::cout << "3. Get all characters\n";
        std::cout << RETURN_TO_MAIN_MENU << ". Return to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addCharacter();
                break;
            case 2:
                getCharacter();
                break;
            case 3:
                getAllCharacters();
                break;
            case RETURN_TO_MAIN_MENU:
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        if (choice != RETURN_TO_MAIN_MENU) {
            std::cout << "Press Enter to return to the Python Database Interaction menu.\n";
            std::cin.ignore();
            std::cin.get();
        }
    } while (choice != RETURN_TO_MAIN_MENU);
}

// Register the page with the menu system
bool registerPage5 = (registerPage("5", "Python Database", displayPage5, 5), true);
