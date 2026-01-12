
#ifndef AFormFORM_HPP
#define AFormFORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;
// protected: -> Can be access from inharitance
// private: -> Can NOT be access from inharitance. Only this class.
class AForm {

	private:
		const std::string	_name;
		bool				_isSigned;   
		const int			_gradeToSignIt;
		const int			_gradeToExecuteIt;
		void				setGrade(int sign, int exec);

	public:

		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

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

std::ostream& operator<<(std::ostream &oS, const AForm &f);

#endif