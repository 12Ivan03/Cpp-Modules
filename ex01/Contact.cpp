
#include <iostream>
#include "Contact.hpp"

using namespace std;

void Contact::setContactDetails(string fName, string lName, string nName,
								string pNumber, string dSecret) {
	firstName = fName;
	lastName = lName;
	nickname = nName;
	phoneNumber = pNumber;
	darkestSecret = dSecret;
};
