#include "PhoneBook.hpp"

using namespace std;

void putBase() {
	cout << "\nDisplaying all contacts:" << endl;
	cout << " ------------------------------------------- " << endl;
	cout << "|     Index|First Name| Last Name|  nickname|" << endl;
	cout << " ------------------------------------------- " << endl;
}

void	printTableCalumn(string str) {

	if (str.length() > 10)
		cout << str.substr(0, 9) << ".|";
	else
		cout << setw(10) << str << "|";
}

void PhoneBook::displayAllContact() const {

	int index;
	int	limit;
	limit = (contactCount < 8) ? contactCount : 8;
	putBase();

	if (contactCount == 0) {
		cout << "|                  This phone book is empty.|" << endl;
		cout << " ------------------------------------------- \n" << endl;
		return;
	};

	for (int i = 0; i < limit; ++i) {
		cout << "|         " << i + 1 << "|";
		printTableCalumn(contacts[i].getFirstName());
		printTableCalumn(contacts[i].getLastName());
		printTableCalumn(contacts[i].getNickname());
		cout << endl;
		cout << " ------------------------------------------- " << endl;
	};
	cout << endl;
}
