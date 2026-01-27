
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


AForm* createShrubbery(const std::string target) {
	return new ShrubberyCreationForm(target);
};

AForm* requestRobotomy(const std::string target) {
	return new RobotomyRequestForm(target);
};

AForm* pardonPresident(const std::string target) {
	return new PresidentialPardonForm(target);
};


Intern::Intern() {};

Intern::Intern(const Intern &other) {};

Intern& Intern::operator=(const Intern &other) {
	
	if (this != &other)
		return *this;
};

Intern::~Intern() {};

AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget) {

	std::string arrFormName[3] = {"shrubbery create", "robotomy request", "president pardon"};


	AForm* (*arr_of_obj[3])(const std::string) = {
		&createShrubbery,
		&requestRobotomy,
		&pardonPresident
	};

	for (int i = 0; i < 3; i++) {
		if (formName == arrFormName[i]) {
			return arr_of_obj[i];
		}

	}

};


// class Base
// { ; }

// class One : public Base
// { ; }

// class Two : public Base
// { ; }

// Base * Factory(unsigned int number)
// {
//   Base * p_item(NULL);
//   switch (number)
//   {
//     case 1:
//       p_item = new One;
//       break;
//     case 2:
//       p_item = new Two;
//       break;
//     default:
//       p_item = NULL;
//       break;
//   }
//   return p_item;
// }



// The important part: makeForm
// AForm* Intern::makeForm(const std::string &formName,
//                         const std::string &target) const
// {
//     // List of known form names
//     std::string names[3] = {
//         "shrubbery creation",
//         "robotomy request",
//         "presidential pardon"
//     };

//     // Array of creator functions
//     AForm* (*creators[3])(const std::string &) = {
//         &createShrubbery,
//         &createRobotomy,
//         &createPresidential
//     };

//     for (int i = 0; i < 3; i++) {
//         if (formName == names[i]) {
//             std::cout << "Intern creates " << formName << std::endl;
//             return creators[i](target);
//         }
//     }

//     std::cout << "Intern cannot create form: " << formName << std::endl;
//     return NULL;
// }
// The small helper functions (static creators)
// These are usually put at the top of Intern.cpp:

// static AForm* createShrubbery(const std::string &target) {
//     return new ShrubberyCreationForm(target);
// }

// static AForm* createRobotomy(const std::string &target) {
//     return new RobotomyRequestForm(target);
// }

// static AForm* createPresidential(const std::string &target) {
//     return new PresidentialPardonForm(target);
// }
