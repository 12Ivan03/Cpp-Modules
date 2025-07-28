#include "PhoneBook.hpp"

void putBase() {
	std::cout << "\nDisplaying all contacts:" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  nickname|" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
}

void	printTableCalumn(std::string str) {

	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str << "|";
}

void PhoneBook::displayAllContact() const {

	int index;
	int	limit;
	limit = (contactCount < 8) ? contactCount : 8;
	putBase();

	if (contactCount == 0) {
		std::cout << "|                  This phone book is empty.|" << std::endl;
		std::cout << " ------------------------------------------- \n" << std::endl;
		return;
	};

	for (int i = 0; i < limit; ++i) {
		std::cout << "|         " << i + 1 << "|";
		printTableCalumn(contacts[i].getFirstName());
		printTableCalumn(contacts[i].getLastName());
		printTableCalumn(contacts[i].getNickname());
		std::cout << std::endl;
		std::cout << " ------------------------------------------- " << std::endl;
	};
	std::cout << std::endl;
}
