
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// public: 
// OCF:
AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute) : 
		_name(name), 
		_target(target),
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
		_target(other._target),
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
	return "Exception AForm throw: Grade too High";
};

const char* AForm::GradeTooLowException::what() const throw() {
	return "Exception AForm throw: Grade too Low";
};

const char* AForm::TheFormIsNotSigned::what() const throw() {
	return "Exception AFrom throw: Form is not signed";
};

const std::string&	AForm::getName() const 		{ return (_name); };
const std::string&	AForm::getTarget() const 	{ return (_target); };
bool	AForm::getIsSigned() const 				{ return (_isSigned); };
int		AForm::getGradeToSign() const 			{ return (_gradeToSignIt); };
int		AForm::getGradeToExecute() const 		{ return (_gradeToExecuteIt); };

void	AForm::beSigned(const Bureaucrat &b) {
	
	if (b.getGrade() > _gradeToSignIt)
		throw AForm::GradeTooLowException();
	std::cout << " From successfully signed" << std::endl;
	_isSigned = true;
};

// protected:
void	AForm::execute(Bureaucrat const &executor) const {

	if (!this->_isSigned)
		throw AForm::TheFormIsNotSigned();
	if (executor.getGrade() > this->_gradeToExecuteIt)
		throw AForm::GradeTooLowException();
	executeTargetForm();

}

std::ostream& operator<<(std::ostream &oS, const AForm &f) {
	return (oS << "Name: " << f.getName() << "\n" 
			<< "Target: " << f.getTarget() << "\n"
			<< "Signed: " << (f.getIsSigned() ? "true\n" : "false\n")
			<< "Grade to Sign: " << f.getGradeToSign() << "\n"
			<< "Grade to Execute: " << f.getGradeToExecute()); 
};
