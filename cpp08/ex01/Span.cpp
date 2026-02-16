
#include "Span.hpp"

// STL algorithms = STL communicates through iterators

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

	if (_data.size() == _nAmount)
		throw std::runtime_error("addNumber: Not enought space: limit of N is reached");
	_data.push_back(num);
};

int		Span::getData(int idx) {
	return _data[idx];
};

size_t		Span::getSize() {
	return _data.size();
}

int		Span::shortestSpan() const {

	if (_data.size() < 2)
		throw std::runtime_error("shortestSpan: Not enough numbers");

	long smallDist = INT_MAX;
	std::vector<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());

	for (size_t i = 1; i < tmp.size(); i++) {

		long subNum = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
		if (subNum < smallDist)
			smallDist = subNum;
	}
	return (static_cast<int>(smallDist));
};

int		Span::longestSpan() const {

	if (_data.size() < 2)
		throw std::runtime_error("longestSpan: Not enough number");

	std::vector<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());
	long bigDist = static_cast<long>(tmp.back()) - static_cast<long>(tmp.front());

	return (static_cast<int>(bigDist));
};

std::ostream& operator<<(std::ostream& oS, Span& sp) {

	for (size_t i = 0; i < sp.getSize(); i++) {
		oS << sp.getData(i) << " ";
	}
	return oS;
};
