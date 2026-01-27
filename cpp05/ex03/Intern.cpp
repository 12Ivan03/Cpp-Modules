
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// OCF
Intern::Intern() {};

Intern::Intern(const Intern &other) {};

Intern& Intern::operator=(const Intern &other) {
	
	// if (this != &other)
	return *this;
};

Intern::~Intern() {};

// arr->functions 
AForm* createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
};

AForm* requestRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
};

AForm* pardonPresident(const std::string &target) {
	return new PresidentialPardonForm(target);
};

AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget) {

	std::string arrFormName[3] = {"shrubbery create", "robotomy request", "president pardon"};


	AForm* (*arr_of_obj[3])(const std::string&) = {
		&createShrubbery,
		&requestRobotomy,
		&pardonPresident
	};

	for (int i = 0; i < 3; i++) {
		if (formName == arrFormName[i]) {
			return arr_of_obj[i](formTarget);
		}
	}
	std::cout << "No match is cound" << std::endl;
	return (NULL);

};
