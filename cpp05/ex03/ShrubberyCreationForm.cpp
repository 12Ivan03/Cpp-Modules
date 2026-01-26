
#include "ShrubberyCreationForm.hpp"
#include <fstream>

// public:

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", target, 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {

	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

const char* ShrubberyCreationForm::CannotOpenFile::what() const throw() {
	return "Error: Unable to open file!";
}

void	ShrubberyCreationForm::executeTargetForm() const {

	std::string fileName = getTarget() + "_shrubbery";
	std::ofstream MyFile(fileName.c_str());

	if (!MyFile.is_open())
		throw ShrubberyCreationForm::CannotOpenFile();

	MyFile << "Happy tree day\n\n";

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10 - i - 1; j++)
    	    MyFile << " ";
		for (int k = 0; k < i * 2 + 1 ;k++)
        	MyFile << "*";
			
		MyFile << "\n";	
	}
	MyFile << "        | |\n";

	MyFile.close();
};


