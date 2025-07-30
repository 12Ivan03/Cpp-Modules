#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		void setContactDetails(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret);
		std::string getFirstName() const { return firstName; };
		std::string getLastName() const { return lastName; };
		std::string getNickname() const { return nickname; };
		std::string getPhoneNumber() const { return phoneNumber; };
		std::string getDarkestSecret() const { return darkestSecret; };
};

#endif
