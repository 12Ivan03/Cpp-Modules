
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {

	private:
		unsigned int		_nAmount;
		std::vector<int>	_data;

	public:

		// Span();
		Span(unsigned int nAmount);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int num);
		int		getData(int idx);
		// void	printSpan(Span& span);
		// shortestSpan();
		// longestSpan();
		// range();
		// range(size_t name.begin(), size_t name.end());

};

std::ostream& operator<<(std::ostream& oS, Span& sp);

#endif




/*

	1. class Span
		- store N integers -> unsigned int _nAmount
				-> only par passed through constructor;

		- Member functions: 
			-addNumber(); -> add a single number to the Span; 
							if (more than _nAmount)
								throw;

			- shortestSpan();

			- longestSpan();

*/
