
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	inner_devider();
void	put_devider(int test_number);

int	main(void) {

	std::srand(std::time(0));

	try {
		
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