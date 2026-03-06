
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
	{
		float a = 548.215;	
		float b = 12.56531;

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "  /  b = " << b << std::endl;
	}
	{
		double a = 548.2155481;	
		double b = 166512.56531;

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "  /  b = " << b << std::endl;
	}
	{
		std::string a[5] = {"hello","world","how","are","you"};
		std::string b[5] = {"world","hello","how","are","you"};

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << "a = " << a[0] << "  /  b = " << b[0] << std::endl;
		::swap(a[0], b[0]);
		std::cout << "a = " << a[0] << "  /  b = " << b[0] << std::endl;

	}

	std::cout << "\nMIN::" << std::endl;

	{	
		int a = 5;
		int b = 6;

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << ::min(a, b) << std::endl;
	}
	{
		float a = 548.215;	
		float b = 12.56531;

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << ::min(a, b) << std::endl;
	}
	{
		double a = 548.2155481;	
		double b = 166512.56531;

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
		std::string b[5] = {"hi","there","how","are","you"};

		std::cout << "a = " << a << "  /  b = " << b << std::endl;
		std::cout << ::max(a, b) << std::endl;
	}

	// Explicit template -> telling I know what I'mpassing, not necessary 
	// template to decude 
	std::cout << "\nMAX::"  << std::endl;

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

	std::cout << "\n42 exmaple test:"  << std::endl;

	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	
	return 0;
}