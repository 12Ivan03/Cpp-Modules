
#include "Span.hpp"

Span::Span(unsigned int nAmount) : _nAmount(nAmount) {
	_data.reserve(nAmount);
};

Span::Span(const Span &other) {
	_nAmount = other._nAmount;
	_data	= other._data;
};

Span& Span::operator=(const Span &other) {

	if (this != &other) {
		this->_nAmount = other._nAmount;
		this->_data = other._data;
	}
	return *this;
};

Span::~Span() {};

void	Span::addNumber(int num) {
	_data.push_back(num);
};

// void	printSpan(Span& span) {

// 	for (int)
// };

int		getData(int idx) {
	return _data[idx];
};


std::ostream& operator<<(std::ostream& oS, Span& sp) {

	for (size_t i = 0; i < sp._data.size(); i++) {
		oS << getData(i) << " ";
	}
	return oS;
};


// shortestSpan();
// longestSpan();
// range();
