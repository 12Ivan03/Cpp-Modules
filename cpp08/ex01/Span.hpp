
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <stdexcept>
#include <limits.h>

class Span {

	private:
		unsigned int		_nAmount;
		std::vector<int>	_data;

	public:

		Span() = delete;
		Span(unsigned int nAmount);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int num);
		int		getData(int idx);
		size_t	getSize();

		template <typename It>
		void	range(It begin, It end) {

			size_t addElements = std::distance(begin, end);
			if (_data.size() + addElements > _nAmount)
				throw std::runtime_error("range: Not enough space");

			_data.insert(_data.end(), begin, end);
		};
		int		shortestSpan() const;
		int		longestSpan() const;
};

std::ostream& operator<<(std::ostream& oS, Span& sp);

#endif
