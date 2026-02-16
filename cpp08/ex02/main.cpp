
#include "MutantStack.hpp"

int	main(void) {

	MutantStack<int> ms;
	ms.push(12);
	ms.push(11);
	ms.push(6541);
	std::cout << ms.top() << std::endl;
	ms.pop();
	std::cout << ms.top() << std::endl;

	MutantStack<int> msNew = ms;
	std::cout << msNew.top() << std::endl;

	MutantStack<int> msNewNew(msNew);
	msNewNew.push(123);

	ms.push(256236);
	ms.push(5243);
	std::cout << "ms = " << ms.top() << std::endl;
	std::cout << "msNew = " << msNew.top() << std::endl;
	std::cout << "msNewNew = " << msNewNew.top() << std::endl;


	return (0);
}