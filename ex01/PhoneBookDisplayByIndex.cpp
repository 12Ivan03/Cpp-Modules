
#include "PhoneBook.hpp"

void	printFullContantInfo(std::string table, std::string str) {
	std::cout << table << str << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
}

void	putFullBase(int index) {
	std::cout << "\nDisplaying contact details:" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|         Index| " << index << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
}

void	PhoneBook::displayContactByIndex(int index) const {

	if (contacts[index].getFirstName().empty()) {
		std::cout << "No contact found at that index " << index + 1 << "." << std::endl;
		return;
	}
	putFullBase(index + 1);
	printFullContantInfo("|    First Name| " , contacts[index].getFirstName());
	printFullContantInfo("|     Last Name| " , contacts[index].getLastName());
	printFullContantInfo("|      nickname| " , contacts[index].getNickname());
	printFullContantInfo("|  Phone Number| " , contacts[index].getPhoneNumber());
	printFullContantInfo("|Darkest Secret| " , contacts[index].getDarkestSecret());
	std::cout << std::endl;
}
