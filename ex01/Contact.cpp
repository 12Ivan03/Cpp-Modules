
#include <iostream>
#include "Contact.hpp"

void Contact::setContactDetails(std::string fName, std::string lName, std::string nName,
								std::string pNumber, std::string dSecret) {
	firstName = fName;
	lastName = lName;
	nickname = nName;
	phoneNumber = pNumber;
	darkestSecret = dSecret;
};
