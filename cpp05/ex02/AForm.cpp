
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// OCF:
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : 
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

AForm::AForm(const AForm &other)  : 
		_name(other._name), 
		_isSigned(other._isSigned), 
		_gradeToSignIt(other._gradeToSignIt),
		_gradeToExecuteIt(other._gradeToExecuteIt) {};

AForm& AForm::operator=(const AForm &other) {

	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
};

AForm::~AForm() {};

const char* AForm::GradeTooHighException::what() const throw() {
	return "\33[31mException AForm throw: Grade too High\33[0m";
};

const char* AForm::GradeTooLowException::what() const throw() {
	return "\33[31mException AForm throw: Grade too Low\33[0m";
};

const std::string&	AForm::getName() const {
	return (_name);
};

bool	AForm::getIsSigned() const {
	return (_isSigned);
};

int		AForm::getGradeToSign() const {
	return (_gradeToSignIt);
};

int		AForm::getGradeToExecute() const {
	return (_gradeToExecuteIt);
};

void	AForm::beSigned(const Bureaucrat &b) {

	if (b.getGrade() > _gradeToSignIt)
		throw AForm::GradeTooLowException();
	_isSigned = true;
};

std::ostream& operator<<(std::ostream &oS, const AForm &f) {
	return (oS << "Name: " << f.getName() << "\n" 
			<< "Signed: " << (f.getIsSigned() ? "true\n" : "false\n")
			<< "Grade to Sign: " << f.getGradeToSign() << "\n"
			<< "Grade to Execute: " << f.getGradeToExecute()); 
};
