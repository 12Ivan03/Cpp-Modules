
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T, typename F>
void	iter(T* array, const int len, F func) {

	std::cout << "\nthe address of the array: " << array << std::endl;
	for (size_t i = 0; i < len; i++) {
		func(array[i]);
	}
}


template <typename T, typename F>
void	iter(const T* array, const int len, F func) {

	std::cout << "\nthe address of the array: " << array << std::endl;
	for (size_t i  = 0; i < len; i++) {
		func(array[i]);
	}
}

#endif
