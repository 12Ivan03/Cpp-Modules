
#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

void innetTrim(std::string &str) {
	int j = 0;
	int eraseFromStr = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] && str[i] == ' ') {
			j = i;
			while (j < str.length() && str[j] == ' ')
				j++;
			eraseFromStr = j - i - 1;
			if (eraseFromStr)
				str.erase(i + 1, eraseFromStr);
			i++;
		}
	}
}

void edgeTrimStr(std::string &str) {

	int start = str.find_first_not_of(WHITE_SPACE);
	if (start == std::string::npos) {
		str.clear();
		return;
	}
	int end = str.find_last_not_of(WHITE_SPACE);
	str = str.substr(start, end - start + 1);
}

bool	isEmpty(std::string &str) {

	edgeTrimStr(str);
	innetTrim(str);
	if (str.empty()) {
		std::cout << "This filed cannot be empty." << std::endl;
		return true;
	}
	return false;
}

void	askForInput(std::string &str, const std::string &prompt) {

	std::cout << prompt;
	getline(std::cin, str);

	if (std::cin.eof()) {
		std::cout << "Input terminated." << std::endl;
		exit(0);
	}

	while (isEmpty(str)) {
		std::cout << prompt;
		getline(std::cin, str);
	}
}

void	PhoneBook::addContact() {
	std::string fName, lName, nName, pNumber, dSecret;

	askForInput(fName, "Enter first name: ");
	askForInput(lName, "Enter last name: ");
	askForInput(nName, "Enter nickname: ");
	askForInput(pNumber, "Enter phone number: ");
	askForInput(dSecret, "Enter darkest secret: ");

	contacts[contactCount % 8].setContactDetails(fName, lName, nName, pNumber, dSecret);
	contactCount++;
	std::cout << "\nContact added successfully!\n" << std::endl;
}

