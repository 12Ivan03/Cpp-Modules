
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;
// protected: -> can be access from inharitance
// private: -> can NOT be access from inharitance. Only this class.
class Form {

	private:
		const std::string	_name;
		bool				_isSigned;   
		const int			_gradeToSignIt;
		const int			_gradeToExecuteIt;

	public:

		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat &b);
};

std::ostream& operator<<(std::ostream &oS, const Form &f);

#endif