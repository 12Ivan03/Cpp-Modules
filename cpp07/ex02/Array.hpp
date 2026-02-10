
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <exception>

template <typename T>
class Array {

	private: 
		T				*_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int lenArray);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T& operator[](int idx);
		T& operator[](int idx) const;
};

#include "Array.tpp"

#endif