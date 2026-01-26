

// sign 25, exec 5

// Informs that <target> has been pardoned by Zaphod Beeblebox.

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : 
	AForm("PresidentialPardonForm", target, 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
	AForm(other) {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {

	if (this != &other)
		AForm::operator=(other);
	return (*this);
};

PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::executeTargetForm() const {

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};