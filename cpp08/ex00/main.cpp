
#include "easyfind.hpp"

int main(void) {

	std::cout << "__________________________________________________________________________" << std::endl;
	std::cout << "Vector search: \nstd::Vector<int,6> -> search 5 and 10\n" << std::endl;
	{
		std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		try {
			std::vector<int>::iterator it = easyfind(v, 5);
			std::cout << "Vector -> Found: " << *it << std::endl;

			it = easyfind(v, 10);
			std::cout << "Vector -> Found: " << *it << std::endl;
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "__________________________________________________________________________" << std::endl;
	std::cout << "Array search: \nstd::Array<int,6> -> search 5 and 10\n" << std::endl;
	{
		std::array<int,6> ar = {1, 2, 3, 4, 5, 6};
		try
		{
			std::array<int, 6>::iterator it = easyfind(ar, 5);
			std::cout << "Array -> Found: " << *it << std::endl;

			it = easyfind(ar, 10);
			std::cout << "Array -> Found: " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << "__________________________________________________________________________" << std::endl;
	std::cout << "Deque search: \nstd::deque<int> {1..20} -> search 6 and 21\n" << std::endl;
	{
		std::deque<int> d1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 ,17 ,18, 19, 20};
		try
		{
			std::deque<int>::iterator it = easyfind(d1, 6);
			std::cout << "deque -> Found: " << *it << std::endl;

			it = easyfind(d1, 21);
			std::cout << "deque -> Found: " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << "__________________________________________________________________________" << std::endl;
	std::cout << "list search: \nstd::list<int> {1..40} -> search 6, 21 and 65\n" << std::endl;
	{
		std::list<int> myList;
		try
		{
			for (int i = 0; i < 40; i++) {
				myList.push_back(i + 1);
			}

			std::list<int>::iterator it = easyfind(myList, 6);
			std::cout << "list -> Found: " << *it << std::endl;

			it = easyfind(myList, 21);
			std::cout << "list -> Found: " << *it << std::endl;
			
			it = easyfind(myList, 65);
			std::cout << "list -> Found: " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << "__________________________________________________________________________" << std::endl;
	std::cout << "forward_list search: \nstd::forward_list<int> {1..100} -> search 6, 99 and 165\n" << std::endl;
	{
		std::forward_list<int> fl;
		try
		{
			for (int i = 0; i < 100; i++) {
				fl.push_front(i + 1);
			}

			std::forward_list<int>::iterator it = easyfind(fl, 6);
			std::cout << "forward_list -> Found: " << *it << std::endl;

			it = easyfind(fl, 99);
			std::cout << "forward_list -> Found: " << *it << std::endl;
			
			it = easyfind(fl, 165);
			std::cout << "forward_list -> Found: " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return (0);
}