
#include <iostream>
#include "PhoneBook.hpp"

using namespace std;

PhoneBook::PhoneBook() : contactCount(0) {}

bool	isEmpty(string &str) {
	if (str.empty()) {
		cout << "This filed cannot be empty." << endl;
		return true;
	}
	return false;
}

void	askForInput(string &str, const string &prompt) {

	cout << prompt;
	getline(cin, str);

	while (isEmpty(str)) {
		cout << prompt;
		getline(cin, str);
	}
}

void	PhoneBook::addContact() {
	string fName, lName, nName, pNumber, dSecret;

	askForInput(fName, "Enter first name: ");
	askForInput(lName, "Enter last name: ");
	askForInput(nName, "Enter nickname: ");
	askForInput(pNumber, "Enter phone number: ");
	askForInput(dSecret, "Enter darkest secret: ");

	contacts[contactCount % 8].setContactDetails(fName, lName, nName, pNumber, dSecret);
	contactCount++;
	cout << "\nContact added successfully!\n" << endl;
}

