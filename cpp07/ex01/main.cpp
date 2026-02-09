
#include "iter.hpp"

template <typename K>
void	myPrintf(const K& value) {

	std::cout << value << " ";
}

// template <typename K>
// void	increment(K& value) {
// 	value++;
// }

void	increment(int &value) {

	value++;
}

int	main(void) {

	{
		std::cout << "\n NON-CONST - function " << std::endl;

		int arr[5] = {1, 2, 3, 4, 5};
		size_t len = sizeof(arr) / sizeof(arr[0]);

		::iter(arr, len, myPrintf<int>);
		::iter(arr, len, increment);
		::iter(arr, len, myPrintf<int>);

		std::string array[5] = {"hello", "world", "how", "are", "you"};
		len = sizeof(array) / sizeof(array[0]);

		::iter(array, len, myPrintf<std::string>);
	}
	
	{
		std::cout << "\n\n CONST - function " << std::endl;

		const int arr[5] = {1, 2, 3, 4, 5};
		size_t len = sizeof(arr) / sizeof(arr[0]);

		::iter(arr, len, myPrintf<int>);

		const std::string array[5] = {"hello", "world", "how", "are", "you"};
		len = sizeof(array) / sizeof(array[0]);

		::iter(array, len, myPrintf<std::string>);

		std::cout << "\n\n";
	}
	
	return (0);
}
