
#include "identify.hpp"

Base *generate(void) {
	
	int num = std::rand() % 3;

	if (num == 0) {
		// std::cout << "A Object is created:" << std::endl;
		return new A();
	}
	else if (num == 1) {
		// std::cout << "B Object is created:" << std::endl;
		return new B();
	}
	else {
		// std::cout << "C Object is created:" << std::endl;
		return new C();
	}
};

void identify(Base *p) {
	// prints the actual type 
	// of the object pointed to by p A, B or C
	
	// std::cout << "prints the actual type RTTI: " << &p << std::endl;

	if (dynamic_cast<A*>(p) != nullptr)	
		std::cout << "Downcasting to A Object" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "Downcasting to B Object" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "Downcasting to C Object" << std::endl;
	else
		std::cout << "Unknown Object" << std::endl;

};

void identify(Base &p) {
	// prints the actual type of the object reference
	// by A, B or C

	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	 
	 
};