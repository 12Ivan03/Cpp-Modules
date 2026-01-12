
#include "Form.hpp"
#include "Bureaucrat.hpp"

// OCF:
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
		_isSigned(other._isSigned), 
		_gradeToSignIt(other._gradeToSignIt),
		_gradeToExecuteIt(other._gradeToExecuteIt) {};

Form& Form::operator=(const Form &other) {

	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
};

Form::~Form() {};

const char* Form::GradeTooHighException::what() const throw() {
	return "\33[31mException Form throw: Grade too High\33[0m";
};

const char* Form::GradeTooLowException::what() const throw() {
	return "\33[31mException Form throw: Grade too Low\33[0m";
};

const std::string&	Form::getName() const {
	return (_name);
};

bool	Form::getIsSigned() const {
	return (_isSigned);
};

int		Form::getGradeToSign() const {
	return (_gradeToSignIt);
};

int		Form::getGradeToExecute() const {
	return (_gradeToExecuteIt);
};

void	Form::beSigned(const Bureaucrat &b) {

	if (b.getGrade() > _gradeToSignIt)
		throw Form::GradeTooLowException();
	_isSigned = true;
};

std::ostream& operator<<(std::ostream &oS, const Form &f) {
	return (oS << "Name: " << f.getName() << "\n" 
			<< "Signed: " << (f.getIsSigned() ? "true\n" : "false\n")
			<< "Grade to Sign: " << f.getGradeToSign() << "\n"
			<< "Grade to Execute: " << f.getGradeToExecute()); 
};
