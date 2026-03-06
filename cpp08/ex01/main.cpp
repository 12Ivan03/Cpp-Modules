
#include "Span.hpp"

int	main(void) {

	// working functions with proper input
	{
		std::cout << "_______1________" << std::endl;
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
		std::cout << "_______2________" << std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan = sp: "  << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan = sp: " << sp.longestSpan() << std::endl;
	}

	// adding number in full sp
	{
		std::cout << "_______3________" << std::endl;

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
		std::cout << "_______4________" << std::endl;

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
		std::cout << "_______5________" << std::endl;

		try {
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
// add a better example of range.


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