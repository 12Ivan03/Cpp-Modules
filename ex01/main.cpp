#include <iostream>
#include "PhoneBook.hpp"

using namespace std;

int main() {
	PhoneBook phoneBook;
	string command;

	while (1)
	{
		cout <<"Enter command (ADD< SEARCH< EXIT): ";
		getline(cin, command);

		if (cin.eof())
			break;

		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContacts();
		} else if (command == "EXIT") {
			break;
		} else {
			cout << "Invalid command." << endl;
		}
	}

	return 0;
}
