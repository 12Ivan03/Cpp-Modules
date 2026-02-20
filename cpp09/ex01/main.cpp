
#include "RPN.hpp"

int	main(int argc, char *argv[]) {


	try
	{
		if (argc != 2)
			throw std::runtime_error(" incomplete arguments: argv[1] \'string of reverse polish notation\'");
		
		RPN rpn(argv[1]);

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << e.what() << '\n';
	}
	
	return (0);
}