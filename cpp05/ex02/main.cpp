
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	inner_devider();
void	put_devider(int test_number);

int	main(void) {

	std::srand(time(0));

	try {
		// ~~~~~~~~~~~~~~~~~~~   Test 1    ~~~~~~~~~~~~~~~~~~~

		// Bureaucrat bob("bob", 136);
		// ShrubberyCreationForm home("Form:_C_28");
		
		// put_devider(1);
		// inner_devider();
		// std::cout << "Bureaucrat:" << std::endl << std::endl;
		// std::cout << bob << std::endl << std::endl;
		// inner_devider();
		// std::cout << "ShrubberyCreation Form:" << std::endl << std::endl;
		// std::cout << home << std::endl << std::endl;

		// // inner_devider();
		// // std::cout << "Trying to execute the form ShrubberyCreationForm:\n >>calling: bob.executeForm(home);<<" << std::endl << std::endl;
		// // bob.executeForm(home);
		// inner_devider();
		// std::cout << "bob singing the form:\n >>calling: >>home.beSigned(bob);<<" << std::endl << std::endl;
		// home.beSigned(bob);

		// inner_devider();
		// std::cout << "AFTER SIGNING: Bureaucrat:" << std::endl << std::endl;
		// std::cout << bob << std::endl << std::endl;
		// inner_devider();
		// std::cout << "AFTER SIGNING: ShrubberyCreation Form:" << std::endl << std::endl;
		// std::cout << home << std::endl << std::endl;

		// inner_devider();
		// std::cout << "Trying to execute the form ShrubberyCreationForm:\n >>calling: bob.executeForm(home);<<" << std::endl << std::endl;
		// bob.executeForm(home);

		// ~~~~~~~~~~~~~~~~~~~   Test 2    ~~~~~~~~~~~~~~~~~~~
		put_devider(2);
		inner_devider();
		Bureaucrat sven("sven", 40);
		RobotomyRequestForm RbtmRqstFrm("Form:_B_27");
		
		std::cout << "Bureaucrat:" << std::endl << std::endl;
		std::cout << sven << std::endl << std::endl;
		inner_devider();
		std::cout << "RobotomyRequestForm Form:" << std::endl << std::endl;
		std::cout << RbtmRqstFrm << std::endl << std::endl;

		// inner_devider();
		// std::cout << "Trying to execute the form RobotomyRequestForm:\n >>calling: sven.executeForm(home);<<" << std::endl << std::endl;
		// sven.executeForm(home);
		inner_devider();
		std::cout << "sven singing the form:\n >>calling: >>home.beSigned(sven);<<" << std::endl << std::endl;
		RbtmRqstFrm.beSigned(sven);

		inner_devider();
		std::cout << "AFTER SIGNING: Bureaucrat:" << std::endl << std::endl;
		std::cout << sven << std::endl << std::endl;
		inner_devider();
		std::cout << "AFTER SIGNING: RobotomyRequestForm Form:" << std::endl << std::endl;
		std::cout << RbtmRqstFrm << std::endl << std::endl;

		inner_devider();
		std::cout << "Trying to execute the form RobotomyRequestForm:\n >>calling: sven.executeForm(RbtmRqstFrm);<<" << std::endl << std::endl;
		sven.executeForm(RbtmRqstFrm);

		// ~~~~~~~~~~~~~~~~~~~   Test 3    ~~~~~~~~~~~~~~~~~~~
		put_devider(2);
		inner_devider();
		Bureaucrat gorge("gorge", 26);
		PresidentialPardonForm robot("Form:_D_32");
		
		std::cout << "Bureaucrat:" << std::endl << std::endl;
		std::cout << gorge << std::endl << std::endl;
		inner_devider();
		std::cout << "PresidentialPardonForm Form:" << std::endl << std::endl;
		std::cout << robot << std::endl << std::endl;

		// inner_devider();
		// std::cout << "Trying to execute the form PresidentialPardonForm:\n >>calling: gorge.executeForm(home);<<" << std::endl << std::endl;
		// gorge.executeForm(home);
		inner_devider();
		std::cout << "gorge singing the form:\n >>calling: >>home.beSigned(gorge);<<" << std::endl << std::endl;
		robot.beSigned(gorge);

		inner_devider();
		std::cout << "AFTER SIGNING: Bureaucrat:" << std::endl << std::endl;
		std::cout << gorge << std::endl << std::endl;
		inner_devider();
		std::cout << "AFTER SIGNING: PresidentialPardonForm Form:" << std::endl << std::endl;
		std::cout << robot << std::endl << std::endl;

		inner_devider();
		std::cout << "Trying to execute the form PresidentialPardonForm:\n >>calling: gorge.executeForm(robot);<<" << std::endl << std::endl;
		gorge.executeForm(robot);

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