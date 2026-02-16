
#include "MutantStack.hpp"

int	main(void) {

	MutantStack<int> ms;
	ms.push(12);
	ms.push(11);
	ms.push(6541);
	std::cout << "ms = " << ms.top() << std::endl;
	ms.pop();
	std::cout << "ms = " << ms.top() << std::endl;

	MutantStack<int> msNew = ms;
	std::cout << "msNew = " << msNew.top() << std::endl;

	MutantStack<int> msNewNew(msNew);
	msNewNew.push(123);

	ms.push(256236);
	ms.push(5243);
	std::cout << "ms = " << ms.top() << std::endl;
	std::cout << "msNew = " << msNew.top() << std::endl;
	std::cout << "msNewNew = " << msNewNew.top() << std::endl;


	MutantStack<int>::iterator it = msNewNew.begin();
	std::cout << "it of msNewNew = " << *it << std::endl;

	MutantStack<int>::iterator itEnd = msNewNew.end();
	--itEnd;
	std::cout << "itEnd of msNewNew = " << *itEnd << std::endl;

	std::cout << "Loop through ms's values "  << std::endl;

	for (auto it = ms.begin(); it != ms.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	{
		MutantStack<std::string> mStr;
		mStr.push("Hello");
		mStr.push(" ");
		mStr.push("World");
		mStr.push("!");

		for (auto it = mStr.begin(); it != mStr.end(); ++it) {
			std::cout << *it;
		}
		std::cout << std::endl;
	}
	return (0);
}