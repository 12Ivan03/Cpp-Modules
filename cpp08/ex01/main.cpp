
#include "Span.hpp"

int	main(void) {

	// working functions with proper input
	{
		Span sp(12);
		sp.addNumber(2);

		std::cout << sp << std::endl;

		std::vector<int> v;
		// generate random number
		std::mt19937 gen(std::random_device{}());
		std::uniform_int_distribution<> dist(-1000, 1000);

		for (size_t i = 0; i < 11; i++) {
			int num = dist(gen);
			v.push_back(num);
		}
		sp.range(v.begin(), v.end());

		std::cout << sp << std::endl;

		int res = sp.shortestSpan();
		std::cout << "shortestSpan = res: " << res << std::endl;

		res = sp.longestSpan();
		std::cout << "longestSpan = res: " << res << std::endl;
	}

	// shown test in subject
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	// adding number in full sp
	{
		try {
			Span sp(3);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);
			std::cout << sp << std::endl;

			// sp.addNumber(7);

		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
			return (1);
		}
	}

	// finding smallest bigest distance in sp with only one number
	{
		try {
			Span sp(1);
			sp.addNumber(2);
			std::cout << sp << std::endl;

			// sp.longestSpan();
			// sp.shortestSpan();
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
			return (1);
		}
	}

	// adding bigger range then sp
	{
		try {
			Span sp(12);
			sp.addNumber(2);

			std::cout << sp << std::endl;

			// std::vector<int> v;
			// // generate random number
			// std::mt19937 gen(std::random_device{}());
			// std::uniform_int_distribution<> dist(-1000, 1000);

			// for (size_t i = 0; i < 21; i++) {
			// 	int num = dist(gen);
			// 	v.push_back(num);
			// }
			// sp.range(v.begin(), v.end());

		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
			return (1);
		}
	}

	// create Span without N
	// {
	// 	try {
	// 		Span sp;
	// 		sp.addNumber(2);
	// 		std::cout << sp << std::endl;

	// 		// sp.longestSpan();
	// 		// sp.shortestSpan();
	// 	} catch (const std::exception& e) {
	// 		std::cout << "Error: " << e.what() << std::endl;
	// 		return (1);
	// 	}
	// }


	return (0);
}