
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <exception>

// class can depend on a type
// Operator overloading work with tempaltes
// Memory handling much work for any T
//  Templates must be fully visible (.tpp)

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

		T&				operator[](unsigned int idx);
		const T&		operator[](unsigned int idx) const;
		unsigned int	size() const;
};

#include "Array.tpp"

#endif
