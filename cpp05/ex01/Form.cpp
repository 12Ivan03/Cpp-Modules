
#include "Form.hpp"


Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : 
		_name(name), 
		_isSigned(false), 
		_gradeToSignIt(gradeToSign),
		_gradeToExecuteIt(gradeToExecute) 
{
	if (_gradeToSignIt < 1 || _gradeToExecuteIt < 1)
		throw GradeTooHighException();
	if (_gradeToSignIt > 150 || _gradeToExecuteIt > 150)
		throw GradeTooLowException();
};

Form::Form(const Form &other)  : 
		_name(other._name), 
		_isSigned(false), 
		_gradeToSignIt(other._gradeToSignIt),
		_gradeToExecuteIt(other._gradeToExecuteIt) {};

Form& Form::operator=(const Form &other) {

	if (this != &other) {
		
	}
};

Form::~Form() {};


const char* Form::GradeTooHighException::what() const throw() {
	return "Exception throw: Grate too Heigh";
};

const char* Form::GradeTooLowException::what() const throw() {
	return "Exception throw: Grate too Low";
};

const std::string&	Form::getName() const {

};

bool	Form::getIsSigned() const {};

int		Form::getGradeToSign() const {};

int		Form::getGradeToExecute() const {};

void	Form::beSigned(const Bureaucrat &b) {};

std::ostream& operator<<(std::ostream &oS, const Form &f) {
	return oS << "";
};
