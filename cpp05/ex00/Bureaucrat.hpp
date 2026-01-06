#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {

	protected:
		const std::string	_name;
		int					_grade;
		void				setGrade(int grade);

	public:

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();		
};

std::ostream& operator<<(std::ostream &oS, const Bureaucrat &b);

#endif