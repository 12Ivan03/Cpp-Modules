
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
		// ::min(a, b);
		std::cout << ::min(a, b) << std::endl;
	}

	{
		std::string a = "hello";
		std::string b = "there";

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		// ::min(a, b);
		std::cout << ::min(a, b) << std::endl;
	}

	std::cout << "MAX::"  << std::endl;

	{	
		int a = 5;
		int b = 6;

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		::max(a, b);
		std::cout << ::max(a, b) << std::endl;
	}

	{
		std::string a = "hello";
		std::string b = "there";

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		::max(a, b);
		std::cout << ::max(a, b) << std::endl;
	}
}