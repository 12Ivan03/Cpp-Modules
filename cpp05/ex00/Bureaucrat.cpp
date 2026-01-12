#include "Bureaucrat.hpp"

// protected:
void				Bureaucrat::setGrade(int grade) {

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();

	_grade = grade;
};

// public:
// orthodox canonical form public:
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	setGrade(_grade);
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : 
	_name(other._name),
	_grade(other._grade) {};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {

	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
};

Bureaucrat::~Bureaucrat() {};

// inharitance from std::exception
const char*			Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
};

const char*			Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
};

const std::string&	Bureaucrat::getName() const {
	return _name;
};

int					Bureaucrat::getGrade() const {
	return _grade;
};

void				Bureaucrat::incrementGrade() {
	setGrade(_grade - 1);
};

void				Bureaucrat::decrementGrade() {
	setGrade(_grade + 1);
};

// overload outout operator from std::
std::ostream& operator<<(std::ostream& oS, const Bureaucrat &b) {
	return oS << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}