
#include "PhoneBook.hpp"

using namespace std;

void	printFullContantInfo(string table, string str) {
	cout << table << str << endl;
	cout << " ------------------------------------------- " << endl;
}

void	putFullBase(int index) {
	cout << "\nDisplaying contact details:" << endl;
	cout << " ------------------------------------------- " << endl;
	cout << "|         Index| " << index << endl;
	cout << " ------------------------------------------- " << endl;
}

void	PhoneBook::displayContactByIndex(int index) const {

	if (contacts[index].getFirstName().empty()) {
		cout << "No contact found at that index " << index + 1 << "." << endl;
		return;
	}
	putFullBase(index + 1);
	printFullContantInfo("|    First Name| " , contacts[index].getFirstName());
	printFullContantInfo("|     Last Name| " , contacts[index].getLastName());
	printFullContantInfo("|      nickname| " , contacts[index].getNickname());
	printFullContantInfo("|  Phone Number| " , contacts[index].getPhoneNumber());
	printFullContantInfo("|Darkest Secret| " , contacts[index].getDarkestSecret());
	cout << endl;
	cout << " ------------------------------------------- " << endl;

}
