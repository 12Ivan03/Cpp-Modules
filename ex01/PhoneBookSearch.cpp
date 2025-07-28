
#include "PhoneBook.hpp"

bool	checkIndexNumber(int num) {

	if (num > 0 && num <= 8)
		return true;
	else
		return false;
}

int		convertStrToInt(std::string str) {

	int num;

	std::stringstream ss(str);
	if ((ss >> num) && ss.eof())
	{
		if (checkIndexNumber(num))
			return num;
	}
	return -1;
}

int		extractNum(std::string &str) {
	int index;

	index = convertStrToInt(str);
	while (index == -1) {
		std::cout << "Please enter a valid index. Number between 1 and 8: ";
		std::getline(std::cin, str);
		index = convertStrToInt(str);
	}
	return (index);
}

void PhoneBook::searchContacts() const {
	displayAllContact();
	std::string str;
	int index;

	std::cout << "Enter the index of the contact you want to view: ";
	std::getline(std::cin, str);
	if (std::cin.eof()) {
		std::cout << "Input terminated." << std::endl;
		exit(0);
	}
	index = extractNum(str) - 1;
	displayContactByIndex(index);
}
