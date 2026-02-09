
#include "whatever.hpp"

int	main(void) {


		std::cout << "SWAP::" << std::endl;
	
	{	
		int a = 5;
		int b = 6;

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "  /  b = " << b << std::endl;
	}

	{
		std::string a = "hello";
		std::string b = "there";

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "  /  b = " << b << std::endl;
	}

	std::cout << "MIN::" << std::endl;

	{	
		int a = 5;
		int b = 6;

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << ::min(a, b) << std::endl;
	}

	{
		std::string a = "hello";
		std::string b = "there";

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << ::min(a, b) << std::endl;
	}

	{
		std::string a[5] = {"hello","world","how","are","you"};
		std::string b[5] = {"hello","world","how","are","you"};

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << ::max(a, b) << std::endl;
	}

	// Explicit template -> telling I know what I'mpassing, not necessary 
	// template to decude 
	std::cout << "MAX::"  << std::endl;

	{	
		int a = 5;
		int b = 6;

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << ::max<int>(a, b) << std::endl;
	}

	{
		std::string a = "hello";
		std::string b = "there";

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << ::max<std::string>(a, b) << std::endl;
	}

}