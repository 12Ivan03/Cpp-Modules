
#include "MutantStack.hpp"

int	main(void) {

	std::cout << "_______________________________________________________"  << std::endl;

	{
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

		std::cout << "\nLoop through ms's values "  << std::endl;

		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "_______________________________________________________"  << std::endl;
	
	{
		std::cout << "\nMutantStack<std::string> mStr;"  << std::endl;

		MutantStack<std::string> mStr;
		mStr.push("Hello");
		mStr.push(" ");
		mStr.push("World");
		mStr.push("!");

		for (MutantStack<std::string>::iterator it = mStr.begin(); it != mStr.end(); ++it) {
			std::cout << *it;
		}
		std::cout << std::endl;
	}

	std::cout << "_______________________________________________________"  << std::endl;

	{
		std::cout << "School test:"  << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";//  << std::endl;
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}

	std::cout << "_______________________________________________________"  << std::endl;

	{
		std::cout << "School test with replaces MutantStack with std::list:"  << std::endl;

		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";//  << std::endl;
			++it;
		}
		std::cout << std::endl;
		std::list<int> s(lst);
	}

	return (0);
}