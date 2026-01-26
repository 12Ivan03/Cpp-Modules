
#ifndef CHRUBBERYCREATIONFORM_HPP
#define CHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();

		class CannotOpenFile : public std::exception {
			public:
				const char* what() const throw();
		};

		virtual void executeTargetForm() const;
};

#endif