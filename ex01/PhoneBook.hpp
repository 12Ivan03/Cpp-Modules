#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

class PhoneBook {
	private:
		Contact contacts[8];
		int contactCount;

	public:
		PhoneBook();
		void addContact();
		void searchContacts() const;
		void displayAllContact() const;
		void displayContactByIndex(int index) const;
};

#endif
