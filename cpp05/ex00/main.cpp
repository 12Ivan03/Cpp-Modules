
#include "Bureaucrat.hpp"

int	main(void) {

	try {
		std::cout << "TEST 1: Create Bob with gread 50" << std::endl;
		Bureaucrat B("Bob", 50);
		std::cout << B << std::endl << std::endl;

		std::cout << "TEST 2: Create Steve with gread 0" << std::endl;
		Bureaucrat S("Steve", 0);
		std::cout << S << std::endl << std::endl;

		std::cout << "TEST 2.a:  Will never show this message: Create Danie with gread 5" << std::endl;
		Bureaucrat G("Danie", 5);
		std::cout << G << std::endl << std::endl;

	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl << std::endl;
	}

	try {
		std::cout << "TEST 3: Will create Danie in a new try: Create Danie with gread 5" << std::endl;
		Bureaucrat G("Danie", 5);
		std::cout << G << std::endl << std::endl;


		std::cout << "TEST 4: Create Grig with gread 6" << std::endl;
		Bureaucrat W("Grig", 6);
		std::cout << W << std::endl;
		std::cout << "The boss of Grig: Calling increase level 3 times" << std::endl;
		for (int i = 0; i < 3; i++) {
			W.incrementGrade();
		}
		std::cout << "Result: " << W.getGrade() << std::endl << std::endl;

		std::cout << "TEST 5: Create Chopin with gread 2" << std::endl;
		Bureaucrat H("Chopin", 2);
		std::cout << H << std::endl;
		std::cout << "The boss of Chopin: Calling increase level 3 times" << std::endl;
		for (int i = 0; i < 3; i++) {
			H.incrementGrade();
		}
		std::cout << "Result: " << H.getGrade() << std::endl << std::endl;


	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl << std::endl;
	}

	try { 

		std::cout << "TEST 6: Create Einaudi with gread 150" << std::endl;
		Bureaucrat R("Einaudi", 150);
		std::cout << R << std::endl;
		std::cout << "The boss of Einaudi: Calling decrease level 3 times" << std::endl;
		for (int i = 0; i < 3; i++) {
			R.decrementGrade();
		}
		std::cout << "Result: " << R.getGrade() << std::endl << std::endl;

	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl << std::endl;
	}

	return (0);
}