#include <iostream>
#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		std::cout <<"Enter command (ADD< SEARCH< EXIT): ";
		getline(std::cin, command);

		if (std::cin.eof())
			break;

		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContacts();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command." << std::endl;
		}
	}

	return 0;
}
