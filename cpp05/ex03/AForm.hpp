
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;
// protected: -> Can be access from inharitance
// private: -> Can NOT be access from inharitance. Only this class.
class AForm {

	private:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;   
		const int			_gradeToSignIt;
		const int			_gradeToExecuteIt;

	protected:
		virtual void executeTargetForm() const = 0;

	public:

		AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class TheFormIsNotSigned : public std::exception {
			public:
				const char* what() const throw();
		};

		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat &b);
		void				execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream &oS, const AForm &f);

#endif