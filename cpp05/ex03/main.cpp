
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	inner_devider();
void	put_devider(int test_number);

int	main(void) {

	std::srand(time(0));

	try {
		put_devider(1);
		inner_devider();
		Bureaucrat bob("bob", 40);
		Intern slave_one;
		Intern slave_two;
		Intern slave_three;
		AForm* rrf;
		AForm* rrf_two;
		AForm* rrf_three;

		rrf = slave_one.makeForm("shrubbery create", "Bender");
		rrf_two = slave_two.makeForm("robotomy request", "Gender_Bender");
		rrf_three = slave_three.makeForm("president pardon", "Bender_Brower");

		std::cout << bob << std::endl;
		inner_devider();
		std::cout << *rrf << std::endl;
		inner_devider();
		std::cout << *rrf_two << std::endl;
		inner_devider();
		std::cout << *rrf_three << std::endl;


	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}

void	put_devider(int test_number) {
	std::cout << "---------------------------------------------------------" << "\n" 
	<< "Test " << test_number << ":" << std::endl << std::endl;
}

void	inner_devider() {
	std::cout << "------------------------------" << "\n";
}