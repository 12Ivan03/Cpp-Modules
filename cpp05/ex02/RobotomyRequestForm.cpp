
// sign 72, exec 45

// Makes some drilling noises, Then informs that <target> 
// has been robotomized succesfullt 50% of the time. 
// Otherwise, it informas that the robotomy failed.

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib> 

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : 
	AForm("RobotomyRequestForm", target, 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
	AForm(other) {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	
	if (this != &other)
		AForm::operator=(other);
	return (*this);
};

RobotomyRequestForm::~RobotomyRequestForm() {};

void RobotomyRequestForm::executeTargetForm() const {

	// std::srand(std::time(0));
	int num = std::rand();
	// std::cout << num << std::endl;
	if (num % 2 == 0) {
		std::cout << "Making some drilling noises" << std::endl;
		std::cout << "The " << getTarget() 
			<< " is robotomized and successfully 50% of the time" 
			<< std::endl;
	} else {
		std::cout << "robotomy failed" << std::endl;
	}

};