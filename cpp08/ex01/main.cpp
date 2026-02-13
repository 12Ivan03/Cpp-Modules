

// std::vector<int>	_data;
// std::list<int>	_data;

// Span sp(3);

// int *array[3] = {1, 2, 3};

// std::array<int> ar;

// range(std::begin(dq), std::end(dq));

#include "Span.hpp"

int	main(void) {

	Span sp(12);
	sp.addNumber(2);

	std::cout << sp << std::endl;
	return (0);
}