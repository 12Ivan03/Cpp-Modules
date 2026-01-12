
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	inner_devider();
void	put_devider(int test_number);

int	main(void) {

	try {

		put_devider(1);
		std::cout << "-->Create Bob with gread 50" << std::endl;
		Bureaucrat bob("Bob", 50);
		std::cout << "bob object with gradeToSign: 75 ; gradeToExecute: 20 :\n" << bob << std::endl;
		inner_devider();
		std::cout << "-->Create tax object:" << std::endl;
		Form tax("TaxForm", 75, 20);
		std::cout << tax << std::endl;
		inner_devider();
		bob.signForm(tax);
		std::cout << tax << std::endl << std::endl;

	} catch (std::exception &e) {
		std::cerr << "\033[31m" << "Exception caught: " << e.what() << "\033[0m" << std::endl;
	}

	try {
		put_devider(2);
		std::cout << "-->Create Bob with gread 100" << std::endl;
		Bureaucrat bob("Bob", 100);
		std::cout << "bob object with gradeToSign: 75 ; gradeToExecute: 20 :\n" << bob << std::endl;
		inner_devider();
		std::cout << "-->Create tax object:" << std::endl;
		Form tax("TaxForm", 75, 20);
		std::cout << tax << std::endl;
		inner_devider();
		bob.signForm(tax);
		std::cout << tax << std::endl;

	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try
	{
		put_devider(3);
		std::cout << "-->Create Jim with gread 120" << std::endl;
		Bureaucrat jim("Jim", 120);
		std::cout << "Jim object:\n" << jim << std::endl;
		inner_devider();
		std::cout << "-->Create income object with gradeToSign: 5 ; gradeToExecute: 195 :" << std::endl;
		Form income("income", 5, 195);
		std::cout << income << std::endl;
		inner_devider();
		jim.signForm(income);
		std::cout << income << std::endl;

	} catch(const std::exception& e) {
		std::cerr << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
	}

	try {
		put_devider(4);
		std::cout << "-->Create Steve with gread 500" << std::endl;
		Bureaucrat steve("Steve", 500);
		std::cout << "Steve object:\n" << steve << std::endl;
		inner_devider();
		std::cout << "-->Create income object:" << std::endl;
		Form income("income", 5, 15);
		std::cout << income << std::endl;
		inner_devider();
		steve.signForm(income);
		std::cout << income << std::endl;

	} catch(const std::exception& e) {
		std::cerr << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
	}
	
	std::cout << "---------------------------------------------------------" << std::endl;

	return (0);
}

void	put_devider(int test_number) {
	std::cout << "---------------------------------------------------------" << "\n" 
	<< "Test " << test_number << ":" << std::endl << std::endl;
}

void	inner_devider() {
	std::cout << "------------------------------" << "\n";
}