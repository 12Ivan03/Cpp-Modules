
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "iostream"

// STL - Standard Template Library
template <typename T>
void	swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template <typename K>
K& min(K& x, K& y) {

	if (x < y)
		return x;
	return y;
}

template <typename P>
P& max(P& x, P& y) {

	if (x > y)
		return x;
	return y;
}

#endif
